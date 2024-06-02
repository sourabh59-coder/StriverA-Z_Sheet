class Solution {
public:
    int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    {
        if(n<0 || m<0 || v[n][m]==1)    return 0;
        if(n==0 && m==0)    return 1;
        

        if(dp[n][m]!=-1)    return dp[n][m];

        int left = fun(v,n-1,m,dp);
        int right = fun(v,n,m-1,dp);

        return dp[n][m] = (left + right);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vector<vector<int>> dp(n, vector<int> (m,-1));

        return fun(v,n-1,m-1,dp);
    }
};
