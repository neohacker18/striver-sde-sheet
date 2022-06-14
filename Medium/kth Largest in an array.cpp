// Link to the problem : https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int> pq;
        for(auto x:v)
        {
            pq.push(x);
        }
        int ans=0;
        while(!pq.empty() && k--)
        {
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};