// Link to the problem :https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        
        string ans="";
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=0;j<strs.size();j++)
            {
                if(i>=strs[j].size())
                    return ans;
                
                if(strs[0][i]!=strs[j][i])
                    return ans;
            }
            ans.push_back(strs[0][i]);
        }
        return ans;
    }
};