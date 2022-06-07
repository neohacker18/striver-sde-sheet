// Link to the problem : https://leetcode.com/problems/unique-paths/


// Simple dfs solution optimised using memoisation

class Solution {
public:
    bool isValid(int i,int j,int m,int n)
    {
        if(i>=m || j>=n || i<0 || j<0)
            return false;
        
        return true;
    }
    int dfs(int i,int j,int m,int n,vector<vector<int>> &dp)
    {
        if(i==m-1 && j==n-1)
            return 1;
        
        if(!isValid(i,j,m,n))
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int right=!isValid(i,j+1,m,n)?0:dfs(i,j+1,m,n,dp);
        int down=!isValid(i+1,j,m,n)?0:dfs(i+1,j,m,n,dp);
        
        return dp[i][j]=down+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(0,0,m,n,dp);
    }
};