// Link to the problem : https://leetcode.com/problems/palindrome-partitioning/


class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++,j--;
        }
        return true;
    }
    void solve(int idx,string s,vector<string>& v)
    {
        if(idx>=s.size())
        {
            ans.push_back(v);
            return;
        }
        string temp="";
        for(int i=idx;i<s.size();i++)
        {
            temp.push_back(s[i]);
            if(isPalindrome(temp))
            {
                v.push_back(temp);
                solve(i+1,s,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0,s,v);
        return ans;
    }
};