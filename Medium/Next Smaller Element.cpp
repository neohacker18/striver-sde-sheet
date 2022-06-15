// Link to the problem : https://www.codingninjas.com/codestudio/problems/1112581?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++)
    {
        int next=arr[i];
        if(st.empty())
        {
            st.push({next,i});
            continue;
        }
        else
        {
            while(!st.empty() && st.top().first>next)
            {
                ans[st.top().second]=next;
                st.pop();
            }
            st.push({next,i});
        }
    }
    while(!st.empty())
    {
        ans[st.top().second]=-1;
        st.pop();
    }
    return ans;
}