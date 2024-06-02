class Solution {
public:
    // int fun(vector<vector<int>> &v,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(m<0 || m>=v[0].size())   return 1e9;
        
    //     if(n==0)    return v[n][m];


    //     if(dp[n][m]!=-1)    return dp[n][m];

    //     int a = v[n][m] + fun(v,n-1,m,dp);
    //     int b = v[n][m] + fun(v,n-1,m-1,dp);
    //     int c = v[n][m] + fun(v,n-1,m+1,dp);
        
    //     return dp[n][m] = min(a,min(b,c));
    // }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size(),m = v[0].size();
        int mini = 1e9;

        // vector<vector<int>> dp(n+1,vector<int> (m+1,1e9));
        vector<int> curr(m+1,1e9), prev(m+1,1e9);

        for(int j=0;j<m;j++)
        {
            prev[j] = v[0][j];
            curr[j] = v[0][j];
        }    
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int a(1e9),b(1e9),c(1e9);

                a = v[i][j] + prev[j];

                if((j-1)>=0)    b = v[i][j] + prev[j-1];

                if((j+1)<m)     c = v[i][j] + prev[j+1];

                curr[j] = min(a,min(b,c));
            }
            prev = curr;
        }

        for(int j=0;j<m;j++)
        {
            mini = min(mini, curr[j]);
        }
        
        return mini;
    }
};
