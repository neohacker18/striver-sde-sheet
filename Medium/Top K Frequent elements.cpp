// Link to the problem : https://leetcode.com/problems/top-k-frequent-elements/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1)
            return {nums[0]};
        
        priority_queue<pair<int,int>> pq;
        sort(nums.begin(),nums.end());
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                cnt++;
            else
            {
                pq.push({cnt,nums[i-1]});
                cnt=1;
            }
        }
        pq.push({cnt,nums[nums.size()-1]});
        vector<int> v;
        while(k-- && !pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};