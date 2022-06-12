// Link to the problem : https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& v,int curr,int target,int i,vector<int>& temp)
    {
        if(i>=v.size())
        {
            if(curr==target)
            ans.push_back(temp);
            
            return;
        }
        if(curr+v[i]<=target)
        {
            temp.push_back(v[i]);
            solve(v,curr+v[i],target,i,temp);
            temp.pop_back();
        }
        solve(v,curr,target,i+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates,0,target,0,temp);
        return ans;
    }
};