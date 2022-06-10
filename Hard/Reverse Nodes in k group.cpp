// Link to the problem : https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head,int k,int n)
    {
        ListNode* curr=head,*prev=NULL,*next=NULL;
        int cnt=0;
        if(k>n)
        {
            return curr;
        }
        while(curr && cnt<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next!=NULL)
            head->next=reverse(next,k,n-k);
        
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* curr=head;
        while(curr)
        {
            n++;
            curr=curr->next;
        }
        return reverse(head,k,n);
    }
};