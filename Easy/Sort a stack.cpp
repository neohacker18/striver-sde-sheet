// Link to the problem : https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


#include<bits/stdc++.h>
void sortStack(stack<int> &stack)
{
	priority_queue<int> pq;
    while(!stack.empty())
    {
        pq.push(-stack.top());
        stack.pop();
    }
    while(!pq.empty())
    {
        stack.push(-pq.top());
        pq.pop();
    }
}