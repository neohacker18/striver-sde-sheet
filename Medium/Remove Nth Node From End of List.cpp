// Link to the problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        
        int size=0;
        ListNode* curr=head;
        while(curr)
        {
            curr=curr->next;
            size++;
        }
        if(size==1)
            return NULL;
        
        n=size-n-1;
        if(n==-1)
        {
            head=head->next;
            return head;
        }
        ListNode* ans=new ListNode(0);
        ans->next=head;
        while(n-- && head)
        {
            head=head->next;
        }
        if(!head || !head->next)
        return ans->next;

        ListNode* temp=head->next;
        head->next=head->next->next;
        delete temp;
        return ans->next;
    }
};