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
        queue<pair<TreeNode*,long long>> qe;
        long long ans = 0;
        if(root)    qe.push({root,0});

        while(!qe.empty())
        {
            long long si = qe.size();
            long long min = qe.front().second;

            for(long long i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                auto node = it.first;
                long long val  = it.second;

                val -= min;
                ans = max(ans,val+1);

                if(node->left)  qe.push({node->left,(2*val)+1});
                if(node->right) qe.push({node->right,(2*val)+2});
            }
        }

        return (int)ans;
    }
};
