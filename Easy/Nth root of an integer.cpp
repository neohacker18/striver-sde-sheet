// Link to the problem : https://www.codingninjas.com/codestudio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#define E 1e-7
double solve(int n,double x)
{
    double ans=1.0;
    for(int i=1;i<=n;i++)
        ans*=x;
    return ans;
}
double findNthRootOfM(int n, long long m) {
    double l=1,r=m;
    while((r-l)>E)
    {
        double mid=(l+r)/2.0;
        if(solve(n,mid)<(double)m)
            l=mid;
        
        else r=mid;
    }
    return l;
}
