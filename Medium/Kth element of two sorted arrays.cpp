// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//  Link to the problem : https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
 
 // } Driver Code Ends
class Solution{
    public:
    int solve(int arr1[],int arr2[],int n,int m,int k,int i,int j)
    {
        if(i==n)
        return arr2[j+k-1];
        
        if(j==m)
        return arr1[i+k-1];
        
        if(k==0 || k>((n-i)+(m-j)))
        return -1;
        
        if(k==1)
        {
            if(arr1[i]<arr2[j])
            return arr1[i];
            
            else return arr2[j];
        }
        int curr=k/2;
        
        if(curr-1>=n-i)
        {
            if(arr1[n-1]<arr2[j+curr-1])
            return arr2[j+k-(n-i)-1];
            
            else return solve(arr1,arr2,n,m,k-curr,i,j+curr);
        }
        if(curr-1>=m-j)
        {
            if(arr1[n-1]<arr2[j+curr-1])
            return arr2[i+k-(m-j)-1];
            
            else return solve(arr1,arr2,n,m,k-curr,i+curr,j);
        }
        else
        {
            if(arr1[curr+i-1]<arr2[curr+j-1])
            return solve(arr1,arr2,n,m,k-curr,i+curr,j);
            
            else return solve(arr1,arr2,n,m,k-curr,i,j+curr);
        }
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        return solve(arr1,arr2,n,m,k,0,0);
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends