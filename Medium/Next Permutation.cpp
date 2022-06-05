Link to the problem : https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        bool flag=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<nums[i+1])
            {   
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int it=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                it=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[it])
            {
                swap(nums[i],nums[it]);
                break;
            }
        }
        reverse(nums.begin()+it+1,nums.end());
    }
};