// Link to the problem : https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
            pq.push(q[i][1]);
        
        else
        {
            if(!pq.empty())
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }
    }
    return ans;
}
