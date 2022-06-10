// Link to the problem :https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        string s="";
        while(head)
        {
            s.push_back(head->val-'0');
            head=head->next;
        }
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
};