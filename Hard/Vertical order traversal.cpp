// Link to the problem:https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {{}};
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,vector<int>> mp;
        while(!q.empty())
        {
            vector<pair<int,int>> v;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                int id=q.front().second;
                q.pop();
                v.push_back({id,curr->val});
                if(curr->left)
                {
                    q.push({curr->left,id-1});
                }
                if(curr->right)
                {
                    q.push({curr->right,id+1});
                }
            }
            sort(v.begin(),v.end(),[](pair<int,int> a,pair<int,int> b){
                    return a.second<b.second;
            });
            for(auto x:v)
            {
                mp[x.first].push_back(x.second);
            }
        }
        vector<vector<int>> ans;
        for(auto x:mp)
        {
            vector<int> v;
            for(auto y:x.second)
                v.push_back(y);
            
            ans.push_back(v);
        }
        return ans;
    }
};