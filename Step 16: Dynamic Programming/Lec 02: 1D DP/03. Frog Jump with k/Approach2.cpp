int fun(vector<int> &v,int ind,int n,int k,vector<int> &dp)
    {
        if(ind==n-1)    return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        
        int ans = INT_MAX;
        
        for(int i=1;i<=k;i++)
        {
            if(n-1-i >= ind)  ans = min(ans, fun(v,ind+i,n,k,dp) + abs(v[ind] - v[ind+i]));
        }
        
        return dp[ind] = ans;
    }
    int minimizeCost(vector<int>& v, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        return fun(v,0,n,k,dp);
    }
