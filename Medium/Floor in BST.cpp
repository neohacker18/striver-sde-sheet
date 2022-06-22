// Link to the problem:https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0


void solve(TreeNode<int>* root,int x,int& ans)
{
    if(!root)return;
    
    if(root->val==x)
    {
        ans=x;
        return;
    }
    if(root->val>x)
    {
        solve(root->left,x,ans);
    }
    else
    {
        if(root->val<x && root->val>ans)
            ans=root->val;
        solve(root->right,x,ans);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    if(!root)
        return -1;
    int ans=INT_MIN;
    solve(root,X,ans);
    return ans;
}