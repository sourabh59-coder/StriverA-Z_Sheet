int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    //   return fun(wt,val,0,n,W,dp);
      
      for(int i=n-1;i>=0;i--)
      {
          for(int j=0;j<=W;j++)
          {
              int notTake = 0 + dp[i+1][j];
              
              int Take = 0;
              
              if(wt[i]<=j)  Take = val[i] + dp[i+1][j-wt[i]];
              
              dp[i][j] = max(Take, notTake);
          }
      }
      
      return dp[0][W];
    }
