// Link to the problem : https://www.codingninjas.com/codestudio/problems/max-xor-queries_1382020?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    vector<int> v;
    sort(arr.begin(),arr.end());
    for(int i=0;i<queries.size();i++)
    {
        int ans=-1;
        for(auto x:arr)
        {
            if(x<=queries[i][1])
            {
                ans=max(ans,x^queries[i][0]);
            }
            else break;
        }
        v.push_back(ans);
    }
    return v;
}