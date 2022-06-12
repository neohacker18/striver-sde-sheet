// Link to the problem : https://leetcode.com/problems/word-break-ii/

class Solution {
public:
    void solve(int index,string s,set<string>& st,vector<string>& ans,vector<string>& v)
    {
        if(index>=s.size())
        {
            string p="";
            for(int i=0;i<v.size()-1;i++)
                p+=v[i]+" ";
            
            p+=v.back();
            ans.push_back(p);
            return;
        }
        string temp="";
        for(int i=index;i<s.size();i++)
        {
            temp.push_back(s[i]);
            if(st.find(temp)!=st.end())
            {
                v.push_back(temp);
                solve(i+1,s,st,ans,v);
                v.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto x:wordDict)
            st.insert(x);
        vector<string> ans;
        vector<string> v;
        solve(0,s,st,ans,v);
        return ans;
    }
};