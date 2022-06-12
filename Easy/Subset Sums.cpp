// Link to the problem : https://practice.geeksforgeeks.org/problems/subset-sums2234/1

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>& arr,int n,int sum,vector<int>& temp)
    {
        if(n==-1)
        return;
        
        temp.push_back(sum+arr[n]);
        solve(arr,n-1,sum+arr[n],temp);
        solve(arr,n-1,sum,temp);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> temp;
        temp.push_back(0);
        solve(arr,N-1,0,temp);
        return temp;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends