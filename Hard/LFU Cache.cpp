// Link to the problem : https://leetcode.com/problems/lfu-cache/



class Node{
    public:
    int cnt,val,key;
    Node* next,*prev;
    Node(int _key,int _val)
    {
        key=_key;
        val=_val;
        cnt=1;
    }
};

class List{
    public:
    int size;
    Node* head,*tail;
    List()
    {
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addNode(Node* node)
    {
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        
        head->next=node;
        temp->prev=node;
        
        size++;
    }
    
    void removeNode(Node* node)
    {
        Node* _prev=node->prev;
        Node* _next=node->next;
        
        _prev->next=_next;
        _next->prev=_prev;
        
        size--;
    }
};

class LFUCache {
public:
    int minFreq,size,currSize;
    unordered_map<int,List*> freq;
    unordered_map<int,Node*> mp;
    
    LFUCache(int capacity) {
        size=capacity;
        currSize=0;
        minFreq=0;
    }
    
    void update(Node* node)
    {
        mp.erase(node->key);
        freq[node->cnt]->removeNode(node);
        
        if(node->cnt==minFreq && freq[node->cnt]->size==0)
            minFreq++;
        
        List* list=new List();
        if(freq[node->cnt+1])
            list=freq[node->cnt+1];
        
        node->cnt++;
        list->addNode(node);
        freq[node->cnt]=list;
        mp[node->key]=node;
    }
        
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        int val=mp[key]->val;
        update(mp[key]);
        return val;
    }
    
    void put(int key, int value) {
        if(size==0)
            return;
        
        if(mp[key])
        {
            Node* node=mp[key];
            node->val=value;
            update(node);
        }
        else
        {
            if(size==currSize)
            {
                List* list=freq[minFreq];
                mp.erase(list->tail->prev->key);
                freq[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq=1;
            List* list=new List();
            if(freq[minFreq])
            {
                list=freq[minFreq];
            }
            Node* node=new Node(key,value);
            list->addNode(node);
            freq[minFreq]=list;
            mp[key]=node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */