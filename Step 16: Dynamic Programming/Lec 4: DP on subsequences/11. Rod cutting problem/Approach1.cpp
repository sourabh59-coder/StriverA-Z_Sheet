int fun(int v[],int ind,int n,int w,vector<vector<int>> &dp)
    {
        if(ind>n)
        {
            return 0;
        }
        
        if(dp[ind][w]!=-1)  return dp[ind][w];
        
        int notTake = 0 + fun(v,ind+1,n,w,dp);
        
        int Take = 0;
        
        if(w >= ind)     Take = v[ind-1] + fun(v,ind,n,w-ind,dp);
        
        return dp[ind][w] = max(Take,notTake);
    }
    int cutRod(int price[], int n) {
        int w = n;
        vector<vector<int>> dp(n+1, vector<int> (w+1, -1));
        return fun(price,1,n,w,dp);
    }
