// Link to the problem :https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;
        int n=haystack.size(),m=needle.size();
        for(int i=0;i<n;i++)
        {
            if(haystack[i]==needle[j])
            {
                int temp=i;
                while(i<n && j<m && haystack[i]==needle[j])
                {
                    i++;
                    j++;
                }
                if(j==m)
                    return temp;
                j=0;
                i=temp;
            }
        }
        return -1;
    }
};