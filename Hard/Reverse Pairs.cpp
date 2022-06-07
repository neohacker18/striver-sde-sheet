// Link to the problem : https://leetcode.com/problems/reverse-pairs/

// Solved using BIT data structure for a more optimised search and updation process

// BST provides a O(n2) solution while BIT provides a O(nlogn) solution.

class Solution {
public:
    int search(vector<int> &bit,int i)
    {
        int sum=0;
        while(i<bit.size())
        {
            sum+=bit[i];
            i+=i&-i;
        }
        return sum;
    }
    void insert(vector<int> &bit,int i)
    {
        while(i>0)
        {
            bit[i]++;
            i-=i&-i;
        }
    }
    int index(vector<int> &v,long val)
    {
        int l=0,r=v.size()-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(v[mid]>=val)
                r=mid-1;
            
            else l=mid+1;
        }
        return l+1;
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        vector<int> copy=nums;
        vector<int> bit(copy.size()+1,0);
        
        sort(copy.begin(),copy.end());
        
        for(auto x:nums)
        {
            ans+=search(bit,index(copy,long(2)*x+1));
            insert(bit,index(copy,x));
        }
        
        return ans;
    }
};