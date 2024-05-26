class Solution {
public:
    // int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
    // {
    //     if(ind==n)
    //     {
    //         if(k==0)    return 0;
    //         else        return 1e9;
    //     }

    //     if(dp[ind][k]!=-1)      return dp[ind][k];

    //     int notTake = 0 + fun(v,ind+1,n,k,dp);

    //     int Take = INT_MAX;

    //     if(k >= v[ind])     Take = 1 + fun(v,ind,n,k-v[ind],dp);

    //     return dp[ind][k] = min(Take,notTake);
    // }
    int coinChange(vector<int>& v, int k) {
        int n = v.size();
        // vector<vector<int>> dp(n+1, vector<int> (k+1,1e9));

        vector<int> curr(k+1, 1e9);
        vector<int> next(k+1, 1e9);

        // int res = fun(v,0,n,k,dp);
        // return (res >= 1e9) ? -1:res;
        for(int i=0;i<=n;i++)   curr[0] = 0;
        for(int i=0;i<=n;i++)   next[0] = 0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                int notTake = 0 + next[j];

                int Take= INT_MAX;

                if(j >= v[i])   Take = 1 + curr[j-v[i]];

                curr[j] = min(Take,notTake);
            }
            next = curr;
        }

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(curr[j] >= 1e9) curr[j] = -1;
            }
        }

        return curr[k];
    }
};
