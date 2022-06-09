// Link to the problem : https://leetcode.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        if(!head)
            return head;
            
        int n=0;
        ListNode* curr=head;
        while(head)
        {
            n++;
            head=head->next;
        }
        n>>=1;
        while(n--)
        {
            curr=curr->next;
        }
        return curr;
    }
};