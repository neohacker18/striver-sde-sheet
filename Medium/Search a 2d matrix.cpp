// Link to the problem :  https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            int lo=0,hi=m-1;
            if(target>matrix[i][hi])
                continue;
            
            while(lo<=hi)
            {
                int mid=(lo+hi)/2;
                if(matrix[i][mid]==target)
                    return true;
                
                else if(matrix[i][mid]>target)
                    hi=mid-1;
                
                else lo=mid+1;
            }
        }
        return false;
    }
};