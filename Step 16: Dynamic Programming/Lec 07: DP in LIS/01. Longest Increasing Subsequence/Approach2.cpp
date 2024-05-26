class Solution {
public:
    // int fun(vector<int> &v,int ind,int n,int prev,vector<vector<int>> &dp)
    // {
    //     if(ind == n+1)    return 0;

    //     if(dp[ind][prev]!=-1)   return dp[ind][prev];

    //     int notTake = 0 + fun(v,ind+1,n,prev,dp);

    //     int Take = 0;

    //     if(prev==0 || v[prev-1] < v[ind-1])     Take = 1 + fun(v,ind+1,n,ind,dp);

    //     return dp[ind][prev] = max(Take,notTake);
    // }
    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+2, vector<int> (n+2,0));
        // return fun(v,1,n,0,dp);

        for(int i=n;i>=1;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int notTake = 0 + dp[i+1][j];

                int Take = 0;

                if(j==0 || v[j-1] < v[i-1])     Take = 1 + dp[i+1][i];

                dp[i][j] = max(Take,notTake);
            }
        }

        return dp[1][0];
    }
};
