// Link to the problem : https://leetcode.com/problems/rotting-oranges/


class Solution {
public:
    vector<int> v1={0,0,1,-1};
    vector<int> v2={1,-1,0,0};
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=1)
            return false;
        
        return true;
    }
    int bfs(vector<vector<int>> grid)
    {
        int cnt=0,freshCnt=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                    freshCnt++;
            }
        }
        if(freshCnt==0)
            return 0;
        
        while(!q.empty())
        {
            int size=q.size();
            int temp=0;
            while(size--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int dx=x+v1[k];
                    int dy=y+v2[k];
                    if(isValid(dx,dy,grid))
                    {
                        q.push({dx,dy});            
                        temp++;
                        grid[dx][dy]=2;
                    }
                }
            }
            if(temp!=0)
                cnt++;
        }
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    cnt=0;
                    break;
                }
            }
        }
        return cnt==0?-1:cnt;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};