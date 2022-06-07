// Link to the problem : https://leetcode.com/problems/majority-element-ii/

// Solved using modified moores voting algo
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int c1=-1,c2=-1,cnt1=0,cnt2=0;
        for(auto x:arr)
        {
            if(x==c1)
                cnt1++;
            else if(x==c2)
                cnt2++;
            else if(cnt1==0)
            {
                c1=x;
                cnt1++;
            }    
            else if(cnt2==0)
            {
                c2=x;
                cnt2++;
            }    
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        vector<int> ans;
        for(auto x:arr)
        {
            if(c1==x)
                cnt1++;
            else if(c2==x)
                cnt2++;
        }
        if (cnt1>n/3)
            ans.push_back(c1);
        
        if (cnt2>n/3)
            ans.push_back(c2);
        
        return ans;
    }
};