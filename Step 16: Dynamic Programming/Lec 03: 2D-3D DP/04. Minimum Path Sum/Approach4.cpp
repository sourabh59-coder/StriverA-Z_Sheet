class Solution {
public:
    // int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(n==0 && m==0)    return v[0][0];
    //     if(n<0 || m<0)  return 1e9;

    //     if(dp[n][m]!=-1)    return dp[n][m];

    //     int left(0),right(0);

    //     left = v[n][m] + fun(v,n-1,m,dp);

    //     right = v[n][m] + fun(v,n,m-1,dp);

    //     return dp[n][m] = min(left,right);
    // }
    int minPathSum(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1,1e9));
        vector<int> curr(m+1,1e9);
        vector<int> prev(m+1,1e9);

        // return fun(v,n-1,m-1,dp);


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)    curr[0] = v[0][0];
                else
                {
                    int left(1e9),right(1e9);

                    if(i-1>=0)    left = v[i][j] + prev[j];
                    if(j-1>=0)    right = v[i][j] + curr[j-1];

                    curr[j] = min(left,right);
                }
            }
            prev = curr;
        }

        return curr[m-1];
    }
};
