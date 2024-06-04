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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> bfs;
        queue<TreeNode*> qe;
        vector<int> ans;

        if(root)
        {
            qe.push(root);
        }

        while(!qe.empty())
        {
            int si = qe.size();
            vector<int> vec;

            for(int i=0;i<si;i++)
            {
                auto node = qe.front();
                qe.pop();

                vec.push_back(node->val);

                if(node->left)  qe.push(node->left);
                if(node->right) qe.push(node->right);
            }

            bfs.push_back(vec);
        }

        for(int i=0;i<bfs.size();i++)
        {
            ans.push_back(bfs[i].back());
        }

        return ans;
    }
};
