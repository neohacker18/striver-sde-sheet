// Link to the problem:https://leetcode.com/problems/flatten-binary-tree-to-linked-list/


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
    vector<int> v;
    void pre(TreeNode* root)
    {
        if(!root)
            return;
        
        v.push_back(root->val);
        pre(root->left);
        pre(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
        pre(root);
        for(int i=1;i<v.size();i++)
        {
            root->right=new TreeNode(v[i]);
            root->left=NULL;
            root=root->right;
        }
    }
};