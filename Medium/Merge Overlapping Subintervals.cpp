// Link to the problem : https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        sort(inter.begin(),inter.end());
        int n=inter.size();
        if(n==0)
            return inter;
        vector<vector<int>> ans;
        ans.push_back(inter[0]);
        for(int i=0;i<n;i++)
        {
            int l2=inter[i][0];
            int r2=inter[i][1];
            int flag=0;
            for(int j=0;j<ans.size();j++)
            {
                int l1=ans[j][0];
                int r1=ans[j][1];
                if(l2>r1 || r2<l1)
                {
                    continue;
                }
                else
                {
                    ans[j][0]=min(l1,l2);
                    ans[j][1]=max(r2,r1);
                    flag=1;
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back(inter[i]);
            }
        }
        return ans;
    }
};