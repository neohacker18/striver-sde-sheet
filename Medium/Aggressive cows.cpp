// Link to the problem : https://www.spoj.com/problems/AGGRCOW/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,cows;
int positions[N];

bool canPlaceCows(int minDist)
{
    int lastPos=-1;
    int cnt=cows;
    for(int i=0;i<n;i++)
    {
        if(lastPos==-1)
        {
            lastPos=0;
            cnt--;
        }
        if(positions[i]-lastPos>=minDist)
        {
            lastPos=i;
            cnt--;
        }
    }
    return cnt<=0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>cows;
        for(int i=0;i<n;i++)
        {
            cin>>positions[i];
        }
    }
    int lo=0,hi=1e9;
    while(hi-lo>1)
    {
        int mid=lo+(hi-lo)/2;
        if(canPlaceCows(mid))
        lo=mid;

        else hi=mid-1;
    }
    if(canPlaceCows(hi))
    cout<<hi<<endl;

    else cout<<lo<<endl;
}
