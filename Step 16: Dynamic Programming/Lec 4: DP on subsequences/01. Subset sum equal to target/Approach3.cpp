bool isSubsetSum(vector<int>v, int sum){
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1,0));
        
        for(int i=0;i<n+1;i++)    dp[i][0] = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
                int notTake = dp[i+1][j];
                
                int Take = 0;
                
                if(v[i] <= j)   Take = dp[i+1][j-v[i]];
                
                dp[i][j] = (Take | notTake);
            }
        }
        
        return dp[0][sum];
    }
