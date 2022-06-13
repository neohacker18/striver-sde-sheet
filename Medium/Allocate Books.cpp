// Link to the problem : https://www.interviewbit.com/problems/allocate-books/

bool isPossible(vector<int>&A,int B,int barrier)
{
    int allocatedStudent=1,pages=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>barrier)
        return false;
        
        if(pages+A[i]>barrier)
        {
            allocatedStudent++;
            pages=A[i];
        }
        else pages+=A[i];
    }
    return allocatedStudent>B?false:true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size()<B)
    return -1;
    int lo=INT_MIN,hi=0;
    for(auto x:A)
    {
        lo=max(lo,x);
        hi+=x;
    }
    int ans=hi;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(isPossible(A,B,mid))
        {
            ans=min(ans,mid);
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return ans;
}

