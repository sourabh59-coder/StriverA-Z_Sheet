class Solution {
public:
    // int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
    // {
    //     if(ind==n)
    //     {
    //         if(k==0)    return 1;
    //         else        return 0;
    //     }

    //     if(dp[ind][k]!=-1)      return dp[ind][k];

    //     int notTake = fun(v,ind+1,n,k,dp);

    //     int Take = 0;

    //     if(k >= v[ind])     Take = fun(v,ind,n,k-v[ind],dp);

    //     return dp[ind][k] = (notTake + Take);
    // }
    int change(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (k+1,0));
        // return fun(v,0,n,k,dp);
        for(int i=0;i<=n;i++)   dp[i][0] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                int notTake = dp[i+1][j];

                int Take = 0;

                if(j >= v[i])   Take = dp[i][j-v[i]];

                dp[i][j] = (Take + notTake);
            }
        }

        return dp[0][k];
    }

};   
