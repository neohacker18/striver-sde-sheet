// Link to the problem : https://leetcode.com/problems/implement-queue-using-stacks/


class MyQueue {
public:
    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        vector<int> aux;
        while(!s.empty())
        {
            aux.push_back(s.top());
            s.pop();
        }
        int x=aux.back();
        aux.pop_back();
        reverse(aux.begin(),aux.end());
        for(auto y:aux)
            s.push(y);
        
        return x;
    }
    
    int peek() {
        vector<int> aux;
        while(!s.empty())
        {
            aux.push_back(s.top());
            s.pop();
        }
        int x=aux.back();
        reverse(aux.begin(),aux.end());
        for(auto y:aux)
            s.push(y);
        
        return x;
    }
    
    bool empty() {
        return s.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */