// Link to the problem : https://leetcode.com/problems/rotate-image/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(matrix[j][i],matrix[i][j]);
            }
        }
    }
};


// if the matrix is not a square matrix --->

#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int up=0,down=n-1,left=0,right=m-1;
    if(down==0 || right==0)
        return;
    while(up<down && left<right)
    {
        int temp=mat[up][up]; 
        for(int i=left+1;i<=right;i++)
        {
            swap(temp,mat[up][i]);
        }
        for(int i=up+1;i<=down;i++)
        {
            swap(temp,mat[i][right]);
        }
        for(int i=right-1;i>=left;i--)
        {
            swap(temp,mat[down][i]);
        }
        for(int i=down-1;i>=up;i--)
        {
            swap(temp,mat[i][left]);
        }
        down--;
        right--;
        up++;
        left++;
    }
}