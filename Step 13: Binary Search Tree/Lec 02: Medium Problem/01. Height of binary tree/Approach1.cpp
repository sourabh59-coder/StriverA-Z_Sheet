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
    int maxDepth(TreeNode* root) {
        int cnt = 0;
        queue<TreeNode*> qe;
        if(root!=NULL)  qe.push(root);

        while(!qe.empty())
        {
            int n = qe.size();
            cnt++;

            for(int i=0;i<n;i++)
            {
                auto it = qe.front();
                qe.pop();

                if((it->left)!=NULL)     qe.push(it->left);
                if((it->right)!=NULL)    qe.push(it->right);
            }
        }

        return cnt;
    }
};
