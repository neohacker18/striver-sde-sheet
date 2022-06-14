// Link to the problem : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s)
        {
            if(ch=='('||ch=='{'||ch=='[')
                st.push(ch);
            
            else
            {
                if(st.empty())
                    return false;
                
                if(ch==')')
                {
                    if(st.top()!='(')
                        return false;
                    else st.pop();
                }
                else if(ch=='}')
                {
                    if(st.top()!='{')
                        return false;
                    else st.pop();
                    
                }
                else
                {
                    if(st.top()!='[')
                        return false;
                    else st.pop();
                }
            }
        }
        return st.empty();
    }
};