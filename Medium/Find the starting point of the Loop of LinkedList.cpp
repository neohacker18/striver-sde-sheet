// Link to the problem :https://leetcode.com/problems/linked-list-cycle-ii/

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
    bool hasCycle(ListNode* head)
    {
        if(!head || !head->next)
            return false;
        
        if(head->next==head)
            return true;
        
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!hasCycle(head))
            return NULL;
        
        ListNode* slow=head,*fast=head;
        while(fast && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                break;
        }
        while(head!=slow)
        {
            slow=slow->next;
            head=head->next;
        }
        return head;
    }
};