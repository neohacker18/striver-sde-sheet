// Link to the problem:https://www.codingninjas.com/codestudio/problems/981269?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void solve(BinaryTreeNode<int> *root,vector<int>& pre,vector<int>& post,vector<int>& in)
{
    if(!root)
        return;
    pre.push_back(root->data);
    solve(root->left,pre,post,in);
    in.push_back(root->data);
    solve(root->right,pre,post,in);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<vector<int>> ans;
    vector<int> pre,post,in;
    solve(root,pre,post,in);
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}