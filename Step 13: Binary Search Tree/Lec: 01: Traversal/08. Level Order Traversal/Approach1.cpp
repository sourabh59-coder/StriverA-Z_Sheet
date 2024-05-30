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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> qe;
        vector<vector<int>> ans;

        if(root!=NULL)    qe.push(root);

        while(!qe.empty())
        {
            int si = qe.size();
            vector<int> v;

            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                v.push_back(it->val);

                if(it->left!=NULL)    qe.push(it->left);
                if(it->right!=NULL)    qe.push(it->right);
            }

            ans.push_back(v);
        }

        return ans;
    }
};
