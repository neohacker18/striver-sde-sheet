// Link to the problem : https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& v) 
    {
        int n=v.size();
        vector<int> prefix(n),suffix(n);
        prefix[0]=v[0];
        suffix[n-1]=v[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],v[i]);
        } 
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],v[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=min(prefix[i],suffix[i])-v[i];
        }
        return ans;
    }
};