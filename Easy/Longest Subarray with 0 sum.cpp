// Link to the problem :  https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1#

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(auto x:nums)
        {
            s.insert(x);
        }
        for(auto x:s)
        {
            int cnt=0;
            if(s.find(x-1)==s.end())
            {
                cnt=1;
                while(s.find(x+cnt)!=s.end())
                {
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};