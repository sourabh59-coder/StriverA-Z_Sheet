class Solution {
public:
    int fun(vector<int> &v,int ind,int n, vector<int> &dp)
    {
        if(ind>=n)  return 0;

        if(dp[ind]!=-1) return dp[ind];

        int notTake = 0 + fun(v,ind+1,n,dp);

        int Take  = v[ind] + fun(v,ind+2,n,dp);

        return dp[ind] = max(Take , notTake);
    }
    int rob(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n+2,0);
        // return fun(v,0,n,dp);

        for(int i=n-1;i>=0;i--)
        {
            int notTake = 0 + dp[i+1];

            int Take = v[i] + dp[i+2];

            dp[i] = max(Take,notTake);
        }

        return dp[0];
    }
};
