// Link to the problem :https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp;
        for(auto x:s)
            mp[x]++;
        
        for(auto x:t)
        {
            if(mp.find(x)==mp.end())
                return false;
            
            if(mp[x]==0)
                return false;
            
            mp[x]--;
        }
        for(auto x:mp)
        {
            if(x.second!=0)
                return false;
        }
        return true;
    }
};