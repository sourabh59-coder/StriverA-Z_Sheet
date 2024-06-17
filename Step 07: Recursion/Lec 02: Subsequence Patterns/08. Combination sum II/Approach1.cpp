class Solution {
public:
    void fun(vector<int> &v,int ind,int n,int k,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(k==0)
        {
            ans.push_back(ds);
            return;
        }

        for(int i=ind;i<n;i++)
        {
            if(i!=ind && v[i]==v[i-1])  continue;

            if(k>=v[i])
            {
                ds.push_back(v[i]);
                fun(v,i+1,n,k-v[i],ds,ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int n = v.size();
        vector<vector<int>> ans;
        vector<int> ds;
        fun(v,0,n,k,ds,ans);
        return ans;
    }
};
