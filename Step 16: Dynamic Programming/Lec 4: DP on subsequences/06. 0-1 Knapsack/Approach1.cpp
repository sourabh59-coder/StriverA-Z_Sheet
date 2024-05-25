int fun(int wt[],int val[],int ind,int n,int w,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        }
        
        if(dp[ind][w]!=-1)      return dp[ind][w];
        
        int notTake = 0 + fun(wt,val,ind+1,n,w,dp);
        
        int Take = 0;
        
        if(wt[ind] <= w)    Take = val[ind] + fun(wt,val,ind+1,n,w-wt[ind],dp);
        
        return dp[ind][w] = max(Take,notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n+1, vector<int> (W+1, -1));
       return fun(wt,val,0,n,W,dp);
    }
