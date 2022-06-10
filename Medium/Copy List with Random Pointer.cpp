// Link to the problem : https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        if(!head)
            return head;
        
        map<Node*,Node*> mp;
        Node* temp=head;
        Node* newHead=NULL,*curr=NULL;
        while(temp)
        {
            if(!newHead)
            {
                newHead=new Node(temp->val);
                curr=newHead;
            }
            else
            {
                curr->next=new Node(temp->val);
                curr=curr->next;
            }
            mp[temp]=curr;
            curr->random=temp->random;
            temp=temp->next;
        }
        curr=newHead;
        while(curr)
        {
            curr->random=mp[curr->random];
            curr=curr->next;
        }
        return newHead;
    }
};