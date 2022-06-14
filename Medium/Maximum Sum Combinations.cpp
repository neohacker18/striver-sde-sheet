// Link to the problem : https://www.interviewbit.com/problems/maximum-sum-combinations/

#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> st;
        vector<int> v;
        while(k--)
        {
            pair<int,pair<int,int>> curr=pq.top();
            pq.pop();
            
            v.push_back(curr.first);
            int i=curr.second.first;
            int j=curr.second.second;
            int sum=a[i-1]+b[j];
            pair<int, int> temp=make_pair(i-1,j);
            if (st.find(temp) == st.end())
            {
                pq.push({sum,temp});
                st.insert(temp);
            }
            sum=a[i] + b[j-1];
            temp=make_pair(i,j-1);
            if (st.find(temp)==st.end())
            {
                pq.push({sum,temp});
                st.insert(temp);
            }
        }
    return v;
}