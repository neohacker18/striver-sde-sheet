// Link to the problem :www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    int s=n*(n+1)/2;
    int p=n*(n+1)*(2*n+1)/6;
    for(auto x:A)
    {
        s-=x;
        p-=x*x;
    }
    vector<int> ans;
    int x=(p/s+s)/2;
    int y=x-s;
    ans.push_back(y);
    ans.push_back(x);
    return ans;
}
