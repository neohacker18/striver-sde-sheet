// Link to the problem:https://www.codingninjas.com/codestudio/problems/boundary-traversal_790725?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

#include<bits/stdc++.h>
{return root->left==NULL && root->right==NULL;}

void addLeftBoundary(TreeNode<int>* root,vector<int> &res){
    TreeNode<int>* curr=root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);
        if(curr->left) curr=curr->left;
        else
            curr=curr->right;
    }
}
void addLeaf(TreeNode<int>* root,vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left,res);
    if(root->right) addLeaf(root->right,res);
}
void addRightBoundary(TreeNode<int>* root,vector<int> &res){
   TreeNode<int>* curr=root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr=curr->right;
        else
            curr=curr->left;

  }
    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
    
}
vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaf(root,res);
    addRightBoundary(root,res);
    return res;
    
}