class Solution {
public:
    void fun(vector<int> &v,int ind,int n,int k,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(k==0)
        {
            if(ds.size()==n)
            {
                ans.push_back(ds);
            }
            return;
        }

        for(int i=ind;i<v.size();i++)
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
    vector<vector<int>> combinationSum3(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> v = {1,2,3,4,5,6,7,8,9};
        fun(v,0,n,k,ds,ans);
        return ans;
    }
};
