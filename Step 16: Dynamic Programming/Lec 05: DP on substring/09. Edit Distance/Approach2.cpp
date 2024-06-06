class Solution {
public:
    // int fun(string s1,string s2,int i,int j,vector<vector<int>> &dp)
    // {
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;

    //     if(dp[i][j]!=-1)    return dp[i][j];

    //     if(s1[i]==s2[j])    return dp[i][j] = 0+fun(s1,s2,i-1,j-1,dp);

    //     else                return dp[i][j] = min(1+fun(s1,s2,i-1,j-1,dp) , min(1 + fun(s1,s2,i,j-1,dp), 1+fun(s1,s2,i-1,j,dp)));
    // }
    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<vector<int>> dp(n+1, vector<int> (m+1,0));

        for(int i=0;i<=n;i++)   dp[i][0] = i;
        for(int j=0;j<=m;j++)   dp[0][j] = j;


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])    dp[i][j] = dp[i-1][j-1] + 0;
                else                    dp[i][j] = min(dp[i-1][j-1] , min(dp[i-1][j] , dp[i][j-1])) + 1;
            }
        }

        return dp[n][m];
        // return fun(s1,s2,n-1,m-1,dp);
    }
};
