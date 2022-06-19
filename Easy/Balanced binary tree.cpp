// Link to the problem:https://leetcode.com/problems/balanced-binary-tree/

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
class Solution {
public:
    bool flag=true;
    int height(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)>1)flag=0;
        
        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return 1;
        
        height(root);
        return flag;
    }
};