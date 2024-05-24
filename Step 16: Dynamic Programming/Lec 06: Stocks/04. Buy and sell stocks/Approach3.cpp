class Solution {
public:
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (k+1,0)));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int l=1;l<=k;l++)
                {
                    if(j==1)  dp[i][j][l] = max((0+dp[i+1][j][l]),(-v[i]+dp[i+1][1-j][l]));

                    else    dp[i][j][l] = max((0+dp[i+1][j][l]),(v[i]+dp[i+1][1-j][l-1]));
                }
            }
        }

        return dp[0][1][k];
    }
};
