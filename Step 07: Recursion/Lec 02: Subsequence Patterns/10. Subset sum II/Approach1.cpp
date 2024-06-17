class Solution {
public:
    void fun(vector<int> &v,int ind,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        ans.push_back(ds);

        for(int i=ind;i<n;i++)
        {
            if(ind!=i && v[i]==v[i-1])  continue;

            ds.push_back(v[i]);
            fun(v,i+1,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> ds;
        fun(v,0,n,ds,ans);
        return ans;
    }
};
