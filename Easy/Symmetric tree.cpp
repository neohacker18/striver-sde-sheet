// Link to the problem:https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    
    bool isMirror(TreeNode* n1, TreeNode* n2){
        if(!n1 && !n2) return true;
        if(!n1 || !n2) return false;
        if(n1->val != n2->val) return false;
        
        return (isMirror(n1->left, n2->right)) && (isMirror(n1->right, n2->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        
        return isMirror(root->left, root->right);
    }
};