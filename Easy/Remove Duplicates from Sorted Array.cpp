// Link to the problem : https://leetcode.com/problems/remove-duplicates-from-sorted-array/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
                cnt++;
        }
        int j=1,i=0;
        while(j<n)
        {
            if(nums[i]>=nums[j])
                j++;
            else
            {
                swap(nums[i+1],nums[j]);
                i++,j++;
            }
        }
        return n-cnt;
    }
};