// Link to the problem : https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> ans;
    void h(int index,vector<int> arr,vector<int> &temp)
    {
        ans.push_back(temp);
        for(int i=index;i<arr.size();i++)
        {
            if(i!=index && arr[i]==arr[i-1])
                continue;
            
            temp.push_back(arr[i]);
            h(i+1,arr,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        h(0,nums,temp);
        return ans;
    }
};