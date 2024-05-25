// int fun(vector<int> &v,int ind,int n,int k,vector<int> &dp)
    // {
    //     if(ind==n-1)    return 0;
        
    //     if(dp[ind]!=-1) return dp[ind];
        
    //     int ans = INT_MAX;
        
    //     for(int i=1;i<=k;i++)
    //     {
    //         if(n-1-i >= ind)  ans = min(ans, fun(v,ind+i,n,k,dp) + abs(v[ind] - v[ind+i]));
    //     }
        
    //     return dp[ind] = ans;
    // }
    int minimizeCost(vector<int>& v, int n, int k) {
        // Code here
        // vector<int> dp(n,-1);
        // return fun(v,0,n,k,dp);
        
        vector<int> dp(n,0);
        
        for(int i=n-2;i>=0;i--)
        {
            dp[i] = INT_MAX;
            for(int j=1;j<=k;j++)
            {
                if(n-1-j >= i)  dp[i] = min(dp[i], dp[i+j] + abs(v[i] - v[i+j]));
            }
        }
        
        return dp[0];
    }
