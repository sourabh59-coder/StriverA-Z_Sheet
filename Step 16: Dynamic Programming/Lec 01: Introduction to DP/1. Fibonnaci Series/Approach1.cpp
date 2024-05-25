int mod = 1000000007;
    long long int fun(int n, vector<long long int> &dp)
    {
        if(n==0)    return 0;
        if(n==1)    return 1;
        
        if(dp[n]!=-1)   return dp[n];
        
        return dp[n] = (fun(n-1,dp) + fun(n-2,dp)) % mod;
    }
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,0);
        // return fun(n,dp);
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        
        return dp[n];
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n+1,0);
        // return fun(n,dp);
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        
        return dp[n];
    }
