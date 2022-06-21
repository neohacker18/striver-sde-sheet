// Link to the problem:https://leetcode.com/problems/validate-binary-search-tree/


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
    int maxi(TreeNode* root)
    {
        if(!root)
            return 0;
        while(root->right)
            root=root->right;
        
        return root->val;
    }
    int mini(TreeNode* root)
    {
        if(!root)
            return 0;  
        while(root->left)
            root=root->left;
        
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return true;
        
        if(root->left && !root->right)
            return isValidBST(root->left) && maxi(root->left)<root->val;
        
        if(!root->left && root->right)
            return isValidBST(root->right) && mini(root->right)>root->val;
        
        return isValidBST(root->left) && isValidBST(root->right) && maxi(root->left)<root->val                  && mini(root->right)>root->val;   
    }
};