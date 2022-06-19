// Link to the problem:https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    bool solve(TreeNode* root,int val,vector<TreeNode*>& path)
    {
        if(!root)
            return false;
        
        if(root->val==val)
        {
            path.push_back(root);
            return true;
        }
        if(solve(root->left,val,path)||solve(root->right,val,path))
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        
        vector<TreeNode*> p1,p2;
        solve(root,p->val,p1);
        solve(root,q->val,p2);
        int n=min(p1.size(),p2.size());
        reverse(p1.begin(),p1.end());
        reverse(p2.begin(),p2.end());
        for(int i=1;i<n;i++)
        {
            if(p1[i]!=p2[i])
                return p1[i-1];
        }
        return p1[n-1];
    }
};