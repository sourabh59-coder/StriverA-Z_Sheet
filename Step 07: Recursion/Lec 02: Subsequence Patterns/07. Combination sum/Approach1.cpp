class Solution {
public:
    void fun(vector<int> &v,int ind,int n,int k,vector<int> &vec,vector<vector<int>> &ans)
    {
        if(ind==n)
        {
            if(k==0)
            {
                ans.push_back(vec);
            }
            
            return;
        }

        //notTake
        fun(v,ind+1,n,k,vec,ans);

        //Take
        if(v[ind] <= k)
        {
            vec.push_back(v[ind]);
            fun(v,ind,n,k-v[ind],vec,ans);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<vector<int>> ans;
        vector<int> vec;
        fun(v,0,v.size(),k,vec,ans);
        return ans;
    }
};
