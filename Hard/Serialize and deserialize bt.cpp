// Link to the problem:https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string sub(string &data,int i)
    {
        string s;
        while(data[i]!=',' && i<data.size())
        {
            s+=data[i++];
        }
        return s;
    }
    TreeNode* help2(string data,int &i)
    {
        string val=sub(data,i);
        i+=val.size()+1;
        if(val=="X")
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(val));
        root->left=help2(data,i);
        root->right=help2(data,i);
        return root;
    }
    string serialize(TreeNode* r) {
        if(!r)
            return "X";
        else
        return to_string(r->val)+","+serialize(r->left)+","+serialize(r->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return help2(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));