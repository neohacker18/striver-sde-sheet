// Link to the problem : https://leetcode.com/problems/permutations/


class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,vector<int>& temp,bool flag[])
    {
        if(nums.size()==temp.size())
        {
            ans.push_back(temp);
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!flag[i])
            {
                flag[i]=true;
                temp.push_back(nums[i]);
                solve(nums,temp,flag);
                temp.pop_back();
                flag[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        bool freq[n];
        for(int i=0;i<n;i++)
            freq[i]=false;
        vector<int> temp;
        solve(nums,temp,freq);
        return ans;
    }
};