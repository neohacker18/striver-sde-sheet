// Link to the problem : https://leetcode.com/problems/count-and-say/

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string ans="11";
        n-=2;
        while(n--)
        {
            int cnt=1;
            string build="";
            for(int i=1;i<ans.size();i++)
            {
                if(ans[i]==ans[i-1])
                    cnt++;
                if(ans[i]!=ans[i-1])
                {
                    build+=to_string(cnt);
                    build.push_back(ans[i-1]);
                    cnt=1;
                }
            }
            build+=to_string(cnt);
            build.push_back(ans[ans.size()-1]);
            ans=build;
        }
        return ans;
    }
};