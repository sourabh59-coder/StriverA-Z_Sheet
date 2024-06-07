int fun(int v[],int i,int j,vector<vector<int>> &dp)
    {
        if(i==j)    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int steps = v[i-1]*v[k]*v[j] + fun(v,i,k,dp) + fun(v,k+1,j,dp);
            ans = min(ans,steps);
        }
        
        return dp[i][j] = ans;
    }
    int matrixMultiplication(int n, int v[])
    {
        // code here
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return fun(v,1,n-1,dp);
    }
