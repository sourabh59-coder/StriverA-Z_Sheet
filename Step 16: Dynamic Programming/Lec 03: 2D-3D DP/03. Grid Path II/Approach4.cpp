class Solution {
public:
    // int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(n<0 || m<0 || v[n][m]==1)    return 0;
    //     if(n==0 && m==0)    return 1;
        

    //     if(dp[n][m]!=-1)    return dp[n][m];

    //     int left = fun(v,n-1,m,dp);
    //     int right = fun(v,n,m-1,dp);

    //     return dp[n][m] = (left + right);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        // vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        vector<int> curr(m+1,0), prev(m+1,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==1)  curr[j] = 0;
                else if(i==0 && j==0 && v[i][j]==0)
                {
                    curr[j] = 1;
                }
                else
                {
                    int left(0),right(0);

                    if((i-1)>=0)    left = prev[j];

                    if((j-1)>=0)    right = curr[j-1];

                    curr[j] = (left + right);
                }
            }
            prev = curr;
        }

        return curr[m-1];
    }
};
