class Solution {
public:
    int fun(vector<vector<int>> &v,int i,int j,int n,vector<vector<int>> &dp)
    {
        if(i==n-1)
        {
            return (v[i][j]);
        }

        if(dp[i][j]!=-1)    return dp[i][j];

        return dp[i][j] = min(v[i][j] + fun(v,i+1,j,n,dp) , v[i][j] + fun(v,i+1,j+1,n,dp));
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        vector<vector<int>> dp(n, vector<int> (n,-1));
        return fun(v,0,0,n,dp);
    }
};
