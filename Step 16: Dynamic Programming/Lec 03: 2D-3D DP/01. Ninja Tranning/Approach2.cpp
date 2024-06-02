int fun(vector<vector<int>> &v,int n,int prev,vector<vector<int>> &dp)
    {
        if(n==0)
        {
            int maxi = 0;
            
            for(int i=0;i<3;i++)
            {
                if(prev!=i)     maxi = max(maxi,v[0][i]);
            }
            
            return dp[n][prev] = maxi;
        }
        
        if(dp[n][prev]!=-1)     return dp[n][prev];
        
        int maxi = 0;
        
        for(int i=0;i<3;i++)
        {
            if(prev!=i)
            {
                int val = v[n][i] + fun(v,n-1,i,dp);
                
                maxi = max(maxi , val);
            }
        }
        
        return dp[n][prev] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int> (4,-1));
        return fun(points,n-1,3,dp);
    }
