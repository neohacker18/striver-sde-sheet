// Link to the problem : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int curr=0;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            if(mp.find(target-nums[i])!=mp.end())
            {
                int x=i;
                int y=mp[target-nums[i]];
                if(x==y)
                    continue;
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};