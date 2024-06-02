class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    {
        if(m<0 || m>=v[0].size())   return 1e9;
        
        if(n==0)    return v[n][m];


        if(dp[n][m]!=-1)    return dp[n][m];

        int a = v[n][m] + fun(v,n-1,m,dp);
        int b = v[n][m] + fun(v,n-1,m-1,dp);
        int c = v[n][m] + fun(v,n-1,m+1,dp);
        
        return dp[n][m] = min(a,min(b,c));
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size(),m = v[0].size();
        int mini = 1e9;

        vector<vector<int>> dp(n,vector<int> (m,-1));
        
        for(int i=0;i<m;i++)
        {
            mini = min(mini, fun(v,n-1,i,dp));
        }
        
        return mini;
    }
};
