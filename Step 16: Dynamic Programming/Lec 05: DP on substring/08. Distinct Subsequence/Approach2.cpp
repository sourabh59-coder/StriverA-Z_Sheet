class Solution {
public:
    int fun(string s,string t,int n,int m,vector<vector<int>> &dp)
    {
        if(m<0)    return 1;
        if(n<0 && m>=0) return 0;

        if(dp[n][m]!=-1)    return dp[n][m];

        if(s[n]==t[m])  return dp[n][m] = (fun(s,t,n-1,m-1,dp) + fun(s,t,n-1,m,dp));

        else            return dp[n][m] = (fun(s,t,n-1,m,dp));
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return fun(s,t,n-1,m-1,dp);
    }
};
