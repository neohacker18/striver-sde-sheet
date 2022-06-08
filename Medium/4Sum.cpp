// Link to the problem : https://leetcode.com/problems/4sum

// Naive solution : O(n3)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int _target=target-(nums[i]+nums[j]);
                int l=j+1,r=nums.size()-1;
                while(l<r)
                {
                    if(nums[l]+nums[r]==_target)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        s.insert(v);
                        l++,r--;
                    }
                    else if(nums[l]+nums[r]>_target)
                        r--;
                    
                    else l++;
                }
            }
        }
        for(auto x:s)
        {
            ans.push_back(x);
        }
        return ans;
    }
};