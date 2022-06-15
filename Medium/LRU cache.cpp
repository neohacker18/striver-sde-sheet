// Link to the problem :https://leetcode.com/problems/lru-cache/


class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> v;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;
        
        int it=mp[key]->second;
        v.erase(mp[key]);
        v.push_front({key,it});
        mp[key]=v.begin();
        
        return it;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            v.erase(mp[key]);
            v.push_front({key,value});
            mp[key]=v.begin();
            return;
        }
        v.push_front({key,value});
        mp[key]=v.begin();

        if(mp.size()>cap)
        {
            mp.erase(v.back().first);
            v.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */