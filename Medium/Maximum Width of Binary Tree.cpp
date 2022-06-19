// Link to the problem :https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
            int l,r;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                int curridx=q.front().second-mini;
                q.pop();
                if(i==0)
                    l=curridx;
                
                if(i==size-1)
                    r=curridx;
                
                if(curr->left)
                    q.push({curr->left,curridx*2LL+1});
                
                if(curr->right)
                    q.push({curr->right,curridx*2LL+2});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};