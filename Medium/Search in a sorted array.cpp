// Link to the problem : https://leetcode.com/problems/search-in-rotated-sorted-array/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0,hi=n-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            int inflexion=nums[mid];
            if(target<nums[0] && nums[0]>inflexion || target>=nums[0] && nums[0]<=inflexion)
                inflexion=nums[mid];
            
            else
            {
                if(target<nums[0])
                    inflexion=INT_MIN;
                
                else inflexion=INT_MAX;
            }
            
            if(target==inflexion)
                return mid;
            
            else if(target>inflexion)
                lo=mid+1;
            
            else hi=mid-1;
        }
        return -1;
    }
};