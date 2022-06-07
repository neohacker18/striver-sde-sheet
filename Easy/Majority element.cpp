// Link to the problem :https://leetcode.com/problems/majority-element/

// Using moores voting algo

class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n=arr.size(),votes=0,candidate=-1;
        for(int i=0;i<n;i++)
        {
            if(votes==0)
            {
                candidate=arr[i];
                votes++;
            }
            else
            {
                if(candidate==arr[i])
                    votes++;
                else votes--;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(candidate==arr[i])
                cnt++;
        }
        return cnt>n/2?candidate:-1;
    }
};