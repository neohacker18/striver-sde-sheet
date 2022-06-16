// Link to the problem : https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                string temp="";
                while(i!=s.size() && s[i]!=' ')
                    temp.push_back(s[i++]);
                
                st.push(temp);
            }
        }
        s="";
        while(st.size()>1)
        {
            s+=st.top()+" ";
            st.pop();
        }
        s+=st.top();
        return s;
    }
};