class Solution {
public:
    void fun(vector<int> &v,int ind,vector<vector<int>> &ans)
    {
        if(ind==v.size())
        {
            ans.push_back(v);
            return;
        }

        for(int i=ind;i<v.size();i++)
        {
            swap(v[ind],v[i]);
            fun(v,ind+1,ans);
            swap(v[ind],v[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        fun(v,0,ans);
        return ans;
    }
};
