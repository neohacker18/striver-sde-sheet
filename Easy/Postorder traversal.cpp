// Link to the problem :https://leetcode.com/problems/binary-tree-postorder-traversal/

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
// using recursion
class Solution {
public:
    vector<int> v;
    void solve(TreeNode* root)
    {
        if(!root)
            return;
        
        solve(root->left);
        solve(root->right);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        solve(root);
        return v;
    }
};

//using stack
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* curr=root;
        while(curr || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top();
            st.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
    }
};