// Link to the problem:https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/


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
    TreeNode* solve(vector<int>& pre, int mn , int mx, int &i){
       if(i>=pre.size())
           return NULL;
        
        if(pre[i]<mn  ||  pre[i]>mx)
            return NULL;
        TreeNode* root= new TreeNode(pre[i++]);
        
        root->left=solve(pre,mn,root->val,i);
        root->right=solve(pre,root->val,mx,i);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int i=0;
       return  solve(pre,INT_MIN,INT_MAX,i);
    
    }
};