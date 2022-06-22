// Link to the problem:https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Node{
    public:
    int mx;
    int mn;
    int sum;
    bool isValid;
    Node()
    {
        mx=INT_MIN;
        mn=INT_MAX;
        sum=0;
        isValid=true;
    }
};

class Solution {
public:
    int ans=0;
    Node solve(TreeNode* root)
    {
        if(!root)
            return Node();
        
        Node node;
        Node l=solve(root->left);
        Node r=solve(root->right);
        
        if(l.isValid && r.isValid && l.mx<root->val && r.mn>root->val)
        {
            node.sum=l.sum+r.sum+root->val;
            node.isValid=true;
            node.mn=min(root->val,min(l.mn,r.mn));
            node.mx=max(root->val,max(l.mx,r.mx));
        }
        else
        {
            node.isValid=false;
            node.sum=0;
        }
        ans=max(ans,node.sum);
        return node;
    }
    int maxSumBST(TreeNode* root) {
        if(!root)
            return 0;
        solve(root);
        return max(ans,0);
    }
};