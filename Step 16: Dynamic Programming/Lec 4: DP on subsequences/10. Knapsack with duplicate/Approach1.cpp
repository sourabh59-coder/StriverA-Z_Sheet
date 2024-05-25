int fun(int val[],int wt[],int ind,int n,int w,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;
        
        if(w==0)    return 0;
        
        if(dp[ind][w]!=-1)      return dp[ind][w];
        
        int notTake = 0 + fun(val,wt,ind+1,n,w,dp);
        
        int Take = 0;
        
        if(w >= wt[ind])    Take = val[ind] + fun(val,wt,ind,n,w-wt[ind],dp);
        
        return dp[ind][w] = max(Take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int> (W+1,-1));
        return fun(val,wt,0,N,W,dp);
    }
