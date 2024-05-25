int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int> (W+1,0));
        // return fun(val,wt,0,N,W,dp);
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=1;j<=W;j++)
            {
                int notTake = 0 + dp[i+1][j];
                
                int Take = 0;
                
                if(j >= wt[i])      Take = val[i] + dp[i][j-wt[i]];
                
                dp[i][j] = max(Take,notTake);
            }
        }
        
        return dp[0][W];
    }
