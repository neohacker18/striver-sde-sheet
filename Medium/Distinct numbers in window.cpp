// Link to the problem:https://www.interviewbit.com/problems/distinct-numbers-in-window/


vector<int> Solution::dNums(vector<int> &A, int B) {
    map<int,int> mp;
    vector<int> ans;
    for(int i=0;i<A.size();i++)
    {
        if(i<B-1)
        mp[A[i]]++;
        
        else
        {
            mp[A[i]]++;
            mp[A[i-B]]--;
            if(mp[A[i-B]]==0)
            mp.erase(A[i-B]);
            
            ans.push_back(mp.size()-1);
        }
    }
    return ans;
}

