class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2 , vector<int> (4)));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<2;j++)
            {
                dp[i][j][0] = 0;
            }
        }

        for(int j=0;j<2;j++)
        {
            for(int k=0;k<3;k++)
            {
                dp[n][j][k] = 0;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                for(int k=1;k<=2;k++)
                {
                    if(j==1)
                    {
                        dp[i][j][k] = max((0+dp[i+1][j][k]),(-v[i]+dp[i+1][1-j][k]));
                    }

                    else
                    {
                        dp[i][j][k] = max((0+dp[i+1][j][k]),(v[i]+dp[i+1][1-j][k-1]));
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};
