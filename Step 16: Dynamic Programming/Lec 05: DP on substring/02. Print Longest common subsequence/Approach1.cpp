class Solution {
public:
    int fun(string s1,string s2,int i,int j, vector<vector<int>> &dp)
    {
        if(i<0 || j<0)      return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        if(s1[i]==s2[j])    return dp[i][j] = (1 + fun(s1,s2,i-1,j-1,dp));

        else                return dp[i][j] = max(fun(s1,s2,i-1,j,dp) , fun(s1,s2,i,j-1,dp));
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])     dp[i][j] = (1 + dp[i-1][j-1]);

                else                 dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }


        string ans = "";
        int i = n, j = m;

        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }

            else if(dp[i-1][j] >= dp[i][j-1])
            {
                // ans.push_back(s1[i]);
                i--;
            }

            else if(dp[i-1][j] < dp[i][j-1])
            {
                // ans.push_back(s2[j]);
                j--;
            }
        }

        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;

        return dp[n][m];
        // return fun(s1,s2,n-1,m-1,dp);
    }
};
