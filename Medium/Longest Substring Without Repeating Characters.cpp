// Link to the problem : https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        
        int ans=1,start=0;
        map<char,int> mp;
        for(int i=0;i<s.size();i++)
        {
            while(mp[s[i]])
            {
                mp[s[start]]--;
                start++;
            }
            ans=max(ans,i-start+1);
            mp[s[i]]++;
        }
        return ans;
    }
};