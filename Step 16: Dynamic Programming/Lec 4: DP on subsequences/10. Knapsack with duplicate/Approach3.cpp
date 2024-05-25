int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // vector<vector<int>> dp(N+1, vector<int> (W+1,0));
        
        vector<int> curr(W+1,0);
        vector<int> next(W+1,0);
        // return fun(val,wt,0,N,W,dp);
        
        for(int i=N-1;i>=0;i--)
        {
            for(int j=1;j<=W;j++)
            {
                int notTake = 0 + next[j];
                
                int Take = 0;
                
                if(j >= wt[i])      Take = val[i] + curr[j-wt[i]];
                
                curr[j] = max(Take,notTake);
                
                next = curr;
            }
        }
        
        return curr[W];
    }
