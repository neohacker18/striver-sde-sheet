// Link to the problem:https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

void solve(BinaryTreeNode<int>* &root)
{
    if(!root)
        return;
    int child=0;
    int l=root->left!=NULL?child+=root->left->data:0;
    int r=root->right!=NULL?child+=root->right->data:0;
    if(root->data>child)
    {
        if(root->left)
            root->left->data=root->data;
        else if(root->right)
            root->right->data=root->data;
    }
    solve(root->left);
    solve(root->right);
    
    int total=0;
    if(root->left)
        total+=root->left->data;
    if(root->right)
        total+=root->right->data;
    if(root->left || root->right)
        root->data=total;
}
void changeTree(BinaryTreeNode < int > * root) {
    if(!root)
        return;
    solve(root);
}  