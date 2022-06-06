// Link to the problem :

#include <bits/stdc++.h> 

// Brute Force
long long getInversions(long long *arr, int n){
    long long cnt=0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j])
                cnt++;
    }
    return cnt;
}

// Optimised Solution 
#include <bits/stdc++.h>

long long merge(long long *arr,int l,int mid,int r)
{
    int n1=mid-l+1,n2=r-mid;
    long long *a1=new long long[n1];
    long long *a2=new long long[n2];
    for(int i=0;i<n1;i++)
        a1[i]=arr[l+i];
    for(int i=0;i<n2;i++)
        a2[i]=arr[mid+i+1];
    
    int i=0,j=0,k=l;
    long long cnt=0;
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            arr[k++]=a1[i++];
        }
        else
        {
            arr[k++]=a2[j++];
            cnt+=(mid+1)-(l+i);
        }
    }
    while(i<n1)
        arr[k++]=a1[i++];
    while(j<n2)
        arr[k++]=a2[j++];
    
    return cnt;
}
long long mergeSort(long long *arr,int l,int r)
{
    long long cnt=0;
    if(l<r)
    {
        int mid=(l+r)/2;
        cnt+=mergeSort(arr,l,mid);
        cnt+=mergeSort(arr,mid+1,r);
        cnt+=merge(arr,l,mid,r);
    }
    return cnt;
}
long long getInversions1(long long *arr, int n){
    return mergeSort(arr,0,n-1);
}