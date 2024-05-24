class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+1 , vector<int> (2, -1));

        dp[n][1] = 0;
        dp[n][0] = 0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                long long profit;
                if(j==1)
                {
                    profit = max( 0+dp[i+1][1] , -v[i]+dp[i+1][0]);
                }
                else
                {
                    profit = max( 0+dp[i+1][0] , v[i]+dp[i+1][1]);
                }
                dp[i][j] = profit;
            }
        }

        return dp[0][1];
    }
};
