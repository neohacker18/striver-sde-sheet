// Link to the problem : https://leetcode.com/problems/combination-sum-ii/


class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& v,int idx,int target,vector<int>& temp)
    {
        if(target==0)
        ans.push_back(temp);
        
        for(int i=idx;i<v.size();i++)
        {
            if(i!=idx && v[i]==v[i-1])
                continue;
            
            if(target>=v[i])
            {
                temp.push_back(v[i]);
                solve(v,i+1,target-v[i],temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        vector<int> temp;
        solve(v,0,target,temp);
        return ans;
    }
};