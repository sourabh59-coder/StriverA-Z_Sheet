int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])    dp[i][j] = (1 + dp[i-1][j-1]);

                else                    dp[i][j] = 0;

                // cout<<dp[i][j]<<" ";
                ans = max(ans,dp[i][j]);
            }
            cout<<endl;
        }
        
        return ans;
    } 
