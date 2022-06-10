// Link to the problem : https://leetcode.com/problems/intersection-of-two-linked-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
        ListNode* curr1=l1,*curr2=l2;
        int n=0,m=0;
        while(curr1)
        {
            n++;
            curr1=curr1->next;
        }
        while(curr2)
        {
            m++;
            curr2=curr2->next;
        }
        if(n>=m)
        {
            n=n-m;
            while(n--)
                l1=l1->next;
            
            while(l1 && l2 && l1!=l2)
            {
                l1=l1->next;
                l2=l2->next;
            }
            return l1;
        }
            m=m-n;
            while(m--)
                l2=l2->next;
            
            while(l1 && l2 && l1!=l2)
            {
                l1=l1->next;
                l2=l2->next;
            }
            return l1;
    }
};