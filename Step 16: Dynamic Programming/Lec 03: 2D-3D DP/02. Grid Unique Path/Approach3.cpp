class Solution {
public:
    // int fun(int m,int n,vector<vector<int>> &dp)
    // {
    //     if(m==0 && n==0)    return 1;

    //     if(m<0 || n<0)  return 0;

    //     if(dp[m][n]!=-1)    return dp[m][n];

    //     int left = fun(m-1,n,dp);
    //     int right = fun(m,n-1,dp);

    //     return dp[m][n] = (left + right);
    // }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        // return fun(m-1,n-1,dp);
        dp[0][0] = 1;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)    dp[i][j] = 1;
                else
                {
                    int left=0,right=0;
                    if(i-1>=0)     left = dp[i-1][j];
                    if(j-1>=0)     right = dp[i][j-1];

                    dp[i][j] = (left+right);
                }
            }
        }

        return dp[m-1][n-1];
    }
};
