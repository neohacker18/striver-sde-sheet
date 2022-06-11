// Link to the problem : https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<Item> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(arr[i]);
        }
        sort(v.begin(),v.end(),[](Item p,Item q){
            double v1=(double)p.value/(double)p.weight;
            double v2=(double)q.value/(double)q.weight;
            return v1>v2;
        });
        double profit=0;
        int i=0;
        double curr_weight=0;
        for(int i=0;i<n;i++)
        {
            if(curr_weight+v[i].weight<=W)
            {
                curr_weight+=v[i].weight;
                profit+=v[i].value;
            }
            else
            {
                double rem=W-curr_weight;
                profit+=v[i].value*(rem/(double)v[i].weight);
                break;
            }
        }
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends