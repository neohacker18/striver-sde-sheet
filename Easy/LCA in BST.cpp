// Link to the problem:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lca(TreeNode* r,TreeNode* p,TreeNode* q)
    {
        if(!r)
            return NULL;
        
        if(r->val>p->val && r->val>q->val)
            return lca(r->left,p,q);
        else if(r->val<p->val && r->val<q->val)
            return lca(r->right,p,q);
        else
            return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};