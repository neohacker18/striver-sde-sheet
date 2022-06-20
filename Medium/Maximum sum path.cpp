// Link to the problem:https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int ans=INT_MIN;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        int maxl=solve(root->left);
        int maxr=solve(root->right);
        maxl=maxl>=0?maxl:0;
        maxr=maxr>=0?maxr:0;
        ans=max(ans,root->val+maxl+maxr);
        return root->val+max(maxl,maxr);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return root->val;
        solve(root);
        return ans;
    }
};