// Link to the problem :https://www.interviewbit.com/problems/path-to-given-node/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void solve1(TreeNode* root,int B,vector<int>& path,vector<int>& ans)
{
    if(!root)
    return;
    
    if(root->val==B)
    {
        path.push_back(root->val);
        ans=path;
        return;
    }
    if(root->left)
    {
        path.push_back(root->val);
        solve1(root->left,B,path,ans);
        path.pop_back();
    }
    if(root->right)
    {
        path.push_back(root->val);
        solve1(root->right,B,path,ans);
        path.pop_back();
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    if(!A)
    return {};
    
    vector<int> v,ans;
    solve1(A,B,v,ans);
    return ans;
}
