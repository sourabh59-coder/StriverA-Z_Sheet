class Solution {
public:
    // int fun(vector<vector<int>> &v,int i,int j,int n,vector<vector<int>> &dp)
    // {
    //     if(i==n-1)
    //     {
    //         return (v[i][j]);
    //     }

    //     if(dp[i][j]!=-1)    return dp[i][j];

    //     return dp[i][j] = min(v[i][j] + fun(v,i+1,j,n,dp) , v[i][j] + fun(v,i+1,j+1,n,dp));
    // }
    int minimumTotal(vector<vector<int>>& v) {
        int n = v.size();
        // vector<vector<int>> dp(n, vector<int> (n,0));
        vector<int> curr(n,0),next(n,0);
        for(int i=0;i<n;i++)
        {
            next[i] = v[n-1][i];
            curr[i] = v[n-1][i];
        }    

        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                curr[j] = min(v[i][j] + next[j] , v[i][j] + next[j+1]);
            }
            next = curr;
        }

        return curr[0];
        // return fun(v,0,0,n,dp);
    }
};
