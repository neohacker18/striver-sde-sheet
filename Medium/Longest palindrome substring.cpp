// Link to the problem : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int start=-1,end=n;
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            int left=i,right=i;
            while(left>=0 && s[left]==s[right] && right<n)
                left--,right++;
            
            int len=right-left+1;
            if(len>maxLen)
            {
                maxLen=len;
                start=left+1;
                end=right-1;
            }
            
            left=i,right=i+1;
            while(left>=0 && s[left]==s[right] && right<n)
                left--,right++;
            
            len=right-left+1;
            if(len>maxLen)
            {
                maxLen=len;
                start=left+1;
                end=right-1;
            }
        }
        string ans=s.substr(start,end-start+1);
        return ans;
    }
};
       