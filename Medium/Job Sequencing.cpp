// Link to the problem : https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#


// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<Job> a;
       set<int> t;
       for (int i = 0; i < n; ++i) {
           a.push_back(arr[i]);
       }
       for (int i = 0; i <= 100; ++i) {
           t.insert(i);
       }
       
       sort(a.begin(), a.end(), [](Job p, Job q){
           return p.profit > q.profit;
       });
       
       int count = 0, ans = 0;
       for (int i = 0; i < n; ++i) {
           int curr = a[i].dead;
           auto itc = prev(t.upper_bound(curr));
           if (*itc != 0) {
               count++;
               ans += a[i].profit;
               t.erase(itc);
           }
       }
       return {count, ans};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends