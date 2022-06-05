Link to the problem: https://leetcode.com/problems/sort-colors/

//one-pass solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0,i=0,j=nums.size()-1;
        while(i<=j)
        {
            if(nums[i]==0)
            {
                swap(nums[i++],nums[zero++]);
            }
            else if(nums[i]==2)
            {
                swap(nums[j--],nums[i]);
            }
            else i++;
        }
    }
};