int cutRod(int v[], int n) {
        int w = n;
        vector<vector<int>> dp(n+2, vector<int> (w+1, 0));
        // return fun(price,1,n,w,dp);
        
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=w;j++)
            {
                int notTake = 0 + dp[i+1][j];
                
                int Take = 0;
                
                if(j >= i)  Take = v[i-1] + dp[i][j-i];
                
                dp[i][j] = max(Take, notTake);
            }
        }
        
        return dp[0][w];
    }
