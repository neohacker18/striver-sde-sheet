// Link to the problem :https://leetcode.com/problems/3sum/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++)
        {
            if((i>0) && nums[i]==nums[i-1])
                continue;
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    vector<int> aux;
                    aux.push_back(nums[i]);
                    aux.push_back(nums[l]);
                    aux.push_back(nums[r]);
                    ans.push_back(aux);
                    while(l<r && nums[l]==nums[l+1])
                        l++;
                    
                    while(l<r && nums[r]==nums[r-1])
                        r--;
                    
                    l++,r--;
                }
                else if(sum>0)
                    r--;
                
                else l++;
            }
        }
        return ans;
    }
};