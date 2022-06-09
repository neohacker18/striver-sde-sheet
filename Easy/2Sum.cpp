// Link to the problem : https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int curr=0;
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            if(mp.find(target-nums[i])!=mp.end())
            {
                int x=i;
                int y=mp[target-nums[i]];
                if(x==y)
                    continue;
                ans.push_back(x);
                ans.push_back(y);
                return ans;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }
        return ans;
    }
};

// Link to the problem : https://www.codingninjas.com/codestudio/problems/pair-sum_697295?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    int i=0,j=arr.size()-1;
    unordered_map<int,int> mp;
    for(auto x:arr)
    {
        mp[x]++;
    }
    while(i<j)
    {
        if(arr[i]+arr[j]==s)
        {
            if(arr[i]!=arr[j])
            {
                int cnt=mp[arr[i]]*mp[arr[j]];
                while(cnt--)
                {
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    ans.push_back(v);
                }
            }
            else
            {
                int cnt=mp[arr[i]];
                cnt=cnt*(cnt-1)/2;
                while(cnt--)
                {
                    vector<int> v;
                    v.push_back(arr[i]);
                    v.push_back(arr[j]);
                    ans.push_back(v);
                }
             }
            while(arr[i]==arr[i+1] && i<j)
            i++;
            while(arr[j]==arr[j-1] && j>i)
            j--;
            i++,j--;
        }
        else if(arr[i]+arr[j]>s)
            j--;
        else i++;
    }
    return ans;
}