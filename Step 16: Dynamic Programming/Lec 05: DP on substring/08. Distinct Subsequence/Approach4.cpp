class Solution {
public:
    // int fun(string s,string t,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(m<0)    return 1;
    //     if(n<0 && m>=0) return 0;

    //     if(dp[n][m]!=-1)    return dp[n][m];

    //     if(s[n]==t[m])  return dp[n][m] = (fun(s,t,n-1,m-1,dp) + fun(s,t,n-1,m,dp));

    //     else            return dp[n][m] = (fun(s,t,n-1,m,dp));
    // }
    int numDistinct(string s, string t) {
        double n = s.length();
        double m = t.length();
        
        // vector<vector<double>> dp(n+1, vector<double> (m+1, 0));
        vector<double> curr(m+1,0),prev(m+1,0);

        for(double i=0;i<=n;i++)
        {
            prev[0] = 1;
            curr[0] = 1;
        }   

        for(double i=1;i<=n;i++)
        {
            for(double j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])  curr[j] = (prev[j-1] + prev[j]);

                else                curr[j] = (prev[j]);
            }
            prev = curr;
        }

        return (int)curr[m];
    }
};
