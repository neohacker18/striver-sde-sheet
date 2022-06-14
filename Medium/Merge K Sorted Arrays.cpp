// Link to the problem : https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379?leftPanelTab=0


#include<bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(auto x:kArrays)
    {
        for(auto y:x)
            pq.push(y);
    }
    vector<int> v;
    while(!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
