// Link to the problem:https://www.codingninjas.com/codestudio/problems/893106?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0


/*************************************************************
 
    Following is the Binary Tree node structure

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

*************************************************************/
void in(BinaryTreeNode<int>* root,vector<int>& v)
{
     if(!root)
     return;
        
     in(root->left,v);
     v.push_back(root->data);
     in(root->right,v);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    if(!root)
        return NULL;
    
    vector<int> v;
    int i=0;
    in(root,v);
    BinaryTreeNode<int>* new_root=new BinaryTreeNode<int>(v[i]);
    BinaryTreeNode<int>* temp=new_root;
    for(int i=0;i<v.size();i++)
    {
        if(i==0)
        new_root->left=NULL;
        
        else
        new_root->left=new BinaryTreeNode<int>(v[i-1]);
        
        if(i==v.size()-1)
        {
            new_root->right=NULL;
            break;
        }
        new_root->right=new BinaryTreeNode<int>(v[i+1]);
        new_root=new_root->right;
    }
    return temp;
}