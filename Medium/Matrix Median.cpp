// Link to the problem : https://www.interviewbit.com/problems/matrix-median/

int solve(vector<int> v,int x)
{
    int lo=0,hi=v.size()-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(v[mid]<=x)
        lo=mid+1;
        
        else hi=mid-1;
    }
    return lo;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    int lo=1,hi=INT_MAX;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=solve(A[i],mid);
        }
        if(cnt<=(n*m/2))
        lo=mid+1;
        
        else hi=mid-1;
    }
    return lo;
}
