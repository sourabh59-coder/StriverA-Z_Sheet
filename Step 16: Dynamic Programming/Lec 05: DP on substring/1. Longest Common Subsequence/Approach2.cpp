class Solution {
public:
    // int fun(string s1,string s2,int i,int j,int n,int m,vector<vector<int>> &dp)
    // {
    //     if(i==n || j==m)    return 0;

    //     if(dp[i][j]!=-1)    return dp[i][j];

    //     if(s1[i]==s2[j])    return dp[i][j] = (1 + fun(s1,s2,i+1,j+1,n,m,dp));

    //     return dp[i][j] = max(fun(s1,s2,i+1,j,n,m,dp) , fun(s1,s2,i,j+1,n,m,dp));
    // }
    int longestCommonSubsequence(string& s1, string& s2) {
        int n = s1.length();
        int m = s2.length();

        // vector<vector<int>> dp(n+1, vector<int> (m+1,-1));
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));


        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(s1[i] == s2[j])    dp[i][j] = (1 + dp[i+1][j+1]);

                else    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];

        // return fun(s1,s2,0,0,n,m,dp);
    }
};
