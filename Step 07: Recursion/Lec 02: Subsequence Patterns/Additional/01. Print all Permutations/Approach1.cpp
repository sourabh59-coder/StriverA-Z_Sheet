class Solution {
public:
    void fun(vector<int> &v,vector<int> &ds,vector<vector<int>> &ans,vector<int> &check)
    {
        if(ds.size()==v.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<v.size();i++)
        {
            if(check[i]==0)
            {
                ds.push_back(v[i]);
                check[i] = 1;
                fun(v,ds,ans,check);
                ds.pop_back();
                check[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> check(n+1,0);
        fun(v,ds,ans,check);
        return ans;
    }
};
