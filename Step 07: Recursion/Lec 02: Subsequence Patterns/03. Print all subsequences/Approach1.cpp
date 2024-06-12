class Solution {
public:
    void fun(vector<int> &v,int ind,int n,vector<int> &vec,vector<vector<int>> &ans)
    {
        if(ind==n)
        {
            ans.push_back(vec);
            return;
        }

        // notTake
        fun(v,ind+1,n,vec,ans);

        // Take
        vec.push_back(v[ind]);
        fun(v,ind+1,n,vec,ans);
        vec.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> vec;
        int n = v.size();
        fun(v,0,n,vec,ans);
        return ans;
    }
};
