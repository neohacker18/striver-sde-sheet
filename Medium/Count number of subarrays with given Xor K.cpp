// Link to the problem : https://www.codingninjas.com/codestudio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website


#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> mp;
    int preXor=0,cnt=0;
    for(int i=0;i<arr.size();i++)
    {
        preXor=preXor^arr[i];
        if(preXor==x)
            cnt++;
        if(mp.find(preXor^x)!=mp.end())
            cnt+=mp[preXor^x];

        mp[preXor]++;
    }
    return cnt;
}