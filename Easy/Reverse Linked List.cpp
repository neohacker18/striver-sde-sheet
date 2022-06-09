// Link to the problem : https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    void solve(ListNode* &curr,ListNode* &pre) {
        if(curr==NULL)
            return;
        
        if(curr->next==NULL)
            return;
        
        ListNode* temp=pre->next;
        pre->next=curr->next;
        curr->next=curr->next->next;
        pre->next->next=temp;
        solve(curr,pre);
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return head;
        
        ListNode* pre=new ListNode(0),*curr=head;
        pre->next=curr;
        solve(curr,pre);
        return pre->next;
    }
};