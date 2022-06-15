// Link to the problem :https://leetcode.com/problems/online-stock-span/


class StockSpanner {
public:
    vector<int> v;
    stack<int> st;
    int i;
    StockSpanner() {
        i=0;
    }
    
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && price>=v[st.top()])
            st.pop();
        
        if(st.empty())
        {
            st.push(i);
            i++;
            return i;
        }
        else
        {
            int ans=i-st.top();
            st.push(i);
            i++;
            return ans;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */