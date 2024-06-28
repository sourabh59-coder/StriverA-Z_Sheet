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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        if(root==NULL)  return "";

        queue<TreeNode*> qe;
        qe.push(root);

        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            if(it==NULL)    data.append("#,");
            else            data.append(to_string(it->val)+',');

            if(it!=NULL)
            {
                qe.push(it->left);
                qe.push(it->right);
            }
        }

        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)  return NULL;

        string str;
        stringstream s(data);
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> qe;
        qe.push(root);

        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();

            getline(s,str,',');
            if(str=="#")
            {
                it->left = NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                it->left = leftNode;
                qe.push(leftNode);

            }

            getline(s,str,',');
            if(str=="#")
            {
                it->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                it->right = rightNode;
                qe.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
