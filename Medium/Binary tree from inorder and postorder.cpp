// Link to the problem:https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/


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
    TreeNode* solve(vector<int>& in,int s1,int n1,vector<int>& post,int s2,int n2,map<int,int>& mp)
    {
        if(s1>n1 && s2>n2)
            return NULL;
        
        TreeNode* root=new TreeNode(post[n2]);
        int inRoot=mp[root->val];
        int numsLeft=inRoot-s1;
        
        root->left=solve(in,s1,inRoot-1,post,s2,s2+numsLeft-1,mp);
        root->right=solve(in,inRoot+1,n1,post,s2+numsLeft,n2-1,mp);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int,int> mp;
        for(int i=0;i<in.size();i++)
        {
            mp[in[i]]=i;
        }
        TreeNode* root=solve(in,0,in.size()-1,post,0,post.size()-1,mp);
        return root;
    }
};