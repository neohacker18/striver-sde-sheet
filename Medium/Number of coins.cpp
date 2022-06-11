// Link to the problem : https://practice.geeksforgeeks.org/problems/number-of-coins1824/1/#


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int coins[],int m,int v,vector<vector<int>> &dp)
	{
	    if(v==0)
	    return 0;
	    
	    if(m==0)
	    {
	        if(v%coins[0]==0)
	        return v/coins[0];
	        
	        return INT_MAX-1;
	    }
	    
	    if(dp[m][v]!=-1)
	    return dp[m][v];
	    
	    int l=INT_MAX,r=INT_MAX;
	    if(v>=coins[m])
	    l=1+solve(coins,m,v-coins[m],dp);
	    
	    r=solve(coins,m-1,v,dp);
	    
	    return dp[m][v]=min(l,r);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M,vector<int>(V+1,-1));
	    return solve(coins,M-1,V,dp)==INT_MAX-1?-1:solve(coins,M-1,V,dp); 
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends