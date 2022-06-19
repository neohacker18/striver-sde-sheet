// Link to the problem : https://leetcode.com/problems/compare-version-numbers/

class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0;
        int n=v1.size(),m=v2.size();
        int a=0,b=0;
        while(i<n || j<m)
        {
            while(i<n && v1[i]!='.')
            {
                a=a*10+(v1[i]-'0');
                i++;
            }
            while(j<m && v2[j]!='.')
            {
                b=b*10+(v2[j]-'0');
                j++;
            }
            if(a>b)
                return 1;
            
            else if(a<b)
                return -1;
            
            i++,j++;
            a=b=0;
        }
        return 0;
    }
};