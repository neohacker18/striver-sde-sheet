// Link to the problem : https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            ans=max(ans,++curr);
            
            else curr=0;
        }
        return ans;
    }
};