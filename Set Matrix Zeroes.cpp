Link to the problem https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row,col;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        for(auto x:row)
        {
            for(int i=0;i<m;i++)
            {
                matrix[x][i]=0;
            }
        }
        for(auto x:col)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][x]=0;
            }
        }
    }
};