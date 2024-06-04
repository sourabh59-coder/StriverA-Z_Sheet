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
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> qe;

        if(root)    qe.push({root, {0,0}});

        while(!qe.empty())
        {
            int si = qe.size();

            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();

                auto node = it.first;
                int level = it.second.first;
                int v_level = it.second.second;

                mp[v_level][level].insert(node->val);

                if(node->left)  qe.push({node->left,{level+1, v_level - 1}});
                if(node->right) qe.push({node->right,{level+1, v_level + 1}});
            }
        }

        vector<vector<int>> ans;

        for(auto it=mp.begin();it!=mp.end();it++)
        {
            auto mp1 = it->second;
            vector<int> vec;
            for(auto itr=mp1.begin();itr!=mp1.end();itr++)
            {
                auto st = itr->second;
                
                for(auto se=st.begin();se!=st.end();se++)
                {
                    vec.push_back(*se);
                }
            }
            ans.push_back(vec);
        }

        return ans;
    }
};
