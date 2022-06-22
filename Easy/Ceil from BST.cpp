// Link to the problem:https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464?source=youtube&campaign=Striver_Tree_Videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=Striver_Tree_Videos&leftPanelTab=0

void solve(BinaryTreeNode<int>* root,int x,int& ans)
{
    if(!root)return;
    
    if(root->data==x)
    {
        ans=x;
        return;
    }
    if(root->data>x)
    {
        ans=root->data;
        solve(root->left,x,ans);
    }
    else
    {
        solve(root->right,x,ans);
    }
}
int findCeil(BinaryTreeNode<int> *root, int x){
    if(!root)
        return -1;
    int ans=-1;
    solve(root,x,ans);
    return ans;
}
