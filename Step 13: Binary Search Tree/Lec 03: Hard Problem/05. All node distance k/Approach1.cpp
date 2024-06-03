/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root, vector<vector<int>> &adj)
    {
        if(root==NULL)  return;

        if(root->left)
        {
            int a = root->val;
            int b = root->left->val;
            adj[a].push_back(b);
            adj[b].push_back(a);
            fun(root->left,adj);
        }

        if(root->right)
        {
            int a = root->val;
            int b = root->right->val;
            adj[a].push_back(b);
            adj[b].push_back(a);
            fun(root->right,adj);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> adj(501);
        fun(root,adj);
        queue<int> qe;
        vector<int> vis(501,0);
        qe.push(target->val);
        vis[target->val] = 1;
        vector<int> ans;
        k++;

        while(!qe.empty())
        {
            int si = qe.size();
            k--;
            for(int i=0;i<si;i++)
            {
                int node = qe.front();
                qe.pop();

                if(k==0)    ans.push_back(node);

                for(auto child: adj[node])
                {
                    if(!vis[child])
                    {
                        vis[child] = 1;
                        qe.push(child);
                    }
                }
            }
        }

        return ans;
    }
};
