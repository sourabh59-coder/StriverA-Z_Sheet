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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> qe;
        
        if(root)    qe.push(root);
        bool flag = true;
        while(!qe.empty())
        {
            int n = qe.size();
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                auto it = qe.front();
                qe.pop();

                v.push_back(it->val);

                if(it->left)    qe.push(it->left);
                if(it->right)   qe.push(it->right);
            }

            if(!flag)
            {
                reverse(v.begin(),v.end());
            }
            
            flag = !flag;
            ans.push_back(v);
        }

        return ans;
    }
};
