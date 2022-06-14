// Link to the problem : https://leetcode.com/problems/next-greater-element-i/


class Solution {
public:
    vector<int> solve(vector<int> v)
    {
        int n=v.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(v[n-1]);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<v[i])
            {
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(v[i]);
        }
        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> ans=solve(nums2);
        vector<int> v;
        int i=0;
        for(auto x:nums2)
        {
            mp[x]=ans[i++];
        }
        for(int i=0;i<nums1.size();i++)
            v.push_back(mp[nums1[i]]);
        
        return v;
    }
};