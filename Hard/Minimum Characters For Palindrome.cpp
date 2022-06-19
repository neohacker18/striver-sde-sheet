// Link to the problem :https://www.codingninjas.com/codestudio/problems/893000?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
vector<int> solve(string s)
{
    int n=s.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++)
    {
        int len=lps[i-1];
        while(len>0 && s[i]!=s[len])
            len=lps[len-1];
        
        if(s[i]==s[len])
            len++;
        
        lps[i]=len;
    }
    return lps;
}
int minCharsforPalindrome(string s) {
    string t=s;
    reverse(t.begin(),t.end());
    string temp=s+'$'+t;
    auto lps=solve(temp);
    return s.size()-lps.back();
}
