// Link to the problem : https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(knows(c,i))
        {
            c=i;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==c)
            continue;
        if(knows(c,i) || !knows(i,c))
            return -1;
    }
    return c;
}