// Link to the problem:  https://leetcode.com/problems/binary-search-tree-iterator/


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
class BSTIterator {
public:
    vector<int> v;
    int it;
    BSTIterator(TreeNode* root) {
        solve(root);
        it=-1;
    }
    void solve(TreeNode* root)
    {
        if(!root)return;
        
        solve(root->left);
        v.push_back(root->val);
        solve(root->right);
    }
    int next() {
        return (it==v.size()-1?-1:v[++it]);
    }
    
    bool hasNext() {
        return (it==v.size()-1?false:true);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */