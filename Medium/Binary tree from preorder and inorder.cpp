// Link to the problem:https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


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
    TreeNode* solve(vector<int>& pre,int s1,int n1,vector<int>& in,int s2,int n2,map<int,int>& mp)
    {
        if(s1>n1 || s2>n2)
            return NULL;
        
        TreeNode* root=new TreeNode(pre[s1]);
        
        int inroot=mp[root->val];
        int numsLeft=inroot-s2;
        
        root->left=solve(pre,s1+1,s1+numsLeft,in,s2,inroot-1,mp);
        root->right=solve(pre,s1+numsLeft+1,n1,in,inroot+1,n2,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        map<int,int> mp;
        for(int i=0;i<in.size();i++)
        {
            mp[in[i]]=i;
        }
        TreeNode* root=solve(pre,0,pre.size()-1,in,0,in.size()-1,mp);
        return root;
    }
};