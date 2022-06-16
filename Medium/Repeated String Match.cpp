// Link to the problem : https://leetcode.com/problems/repeated-string-match/

class Solution {
public:
    int MOD=1000000;
    int rabin_karp(string src,string target)
    {
        if(src=="" || target=="")
            return -1;
        int n=target.size();
        int power=1;
        for(int i=0;i<n;i++)
        {
            power=(power*31)%MOD;
        }
        int targetCode=0;
        for(int i=0;i<n;i++)
        {
            targetCode=(targetCode*31+target[i])%MOD;
        }
        int hashCode=0;
        for(int i=0;i<src.size();i++)
        {
            hashCode=(hashCode*31+src[i])%MOD;
            if(i<n-1)
                continue;
            if(i>=n)
            {
                hashCode=(hashCode-src[i-n]*power)%MOD;
            }
            if(hashCode<0)
                hashCode+=MOD;
            if(hashCode==targetCode)
            {
                if(src.substr(i-n+1,n)==target)
                    return i-n+1;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        if(a==b)
            return 1;
        int cnt=1;
        string temp=a;
        while(temp.size()<b.size())
        {
            temp+=a;
            cnt++;
        }
        if(temp==b)
            return cnt;
        if(rabin_karp(temp,b)!=-1)
            return cnt;
        if(rabin_karp(temp+a,b)!=-1)
            return cnt+1;
        
        return -1;
    }
};