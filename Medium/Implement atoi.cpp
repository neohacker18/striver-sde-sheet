// Link to the problem : https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        long int sum=0;
        int i=0;
        char sign='+';
        
        while(i<s.size() && s[i]==' ')
        { 
            i++; 
        }
        
        if(s[i]=='-' || s[i]=='+')
        {
            sign=s[i];
            ++i;
        }
        
        for(i;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9' && (sum>=INT_MIN && sum<=INT_MAX))
                sum=(sum*10) + (s[i]-'0');
            
            else break;
        }
        
        if(sign=='+')
        {
            if(sum>=INT_MAX)
                return INT_MAX;
            
            else return sum;
        }
        
        else
        {
            sum*=-1;
            if(sum<=INT_MIN)
                return INT_MIN;
            
            else return sum;
        }
    }
};