int maximumPoints(vector<vector<int>>& v, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (4,0));
        
        dp[0][0] = max(v[0][1],v[0][2]);
        dp[0][1] = max(v[0][0],v[0][2]);
        dp[0][2] = max(v[0][0],v[0][1]);
        dp[0][3] = max(v[0][0], max(v[0][1],v[0][2]));
        
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<4;prev++)
            {
                int maxi = 0;
                
                for(int j=0;j<3;j++)
                {
                    if(prev!=j)
                    {
                        int val = v[i][j] + dp[i-1][j];
                        maxi = max(maxi,val);
                    }
                }
                
                dp[i][prev] = maxi;
            }
        }
        return dp[n-1][3];
        // return fun(v,n-1,3,dp);
    }
