int countPartitions(int n, int d, vector<int>& v) {
        // Code here
        int s = 0;
        for(int i=0;i<n;i++)    s += v[i];
        if((d+s)%2!=0)  return 0;    
        int k = (s+d)/2;
        // vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        // // return fun(v,0,n,k,dp);
        // for(int i=0;i<=n;i++)   dp[i][0] = 1;
        
        vector<int> curr(k+1,0);
        vector<int> next(k+1,0);
        
        curr[0] = 1;
        next[0] = 1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=k;j++)
            {
                int notTake = next[j];
                
                int Take = 0;
                
                if(v[i] <= j)   Take = next[j-v[i]];
                
                curr[j] = (notTake + Take) % mod;
            }
            
            next = curr;
        }
        
        return curr[k];
    }
