class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(k==0)    return 1;
            else        return 0;
        }

        if(dp[ind][k]!=-1)      return dp[ind][k];

        int notTake = fun(v,ind+1,n,k,dp);

        int Take = 0;

        if(k >= v[ind])     Take = fun(v,ind,n,k-v[ind],dp);

        return dp[ind][k] = (notTake + Take);
    }
    int change(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
        return fun(v,0,n,k,dp);
    }
};
