// Link to the problem : https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(mid<nums.size()-1 && nums[mid]==nums[mid+1])
            {
                if((mid+1)%2==0)
                    r=mid-1;
                
                else l=mid+1;
            }
            else if(mid>0 && nums[mid-1]==nums[mid])
            {
                if((mid+1)%2!=0)
                    r=mid+-1;
                
                else l=mid+1;
            }
            else return nums[mid];
        }
        return -1;
    }
};