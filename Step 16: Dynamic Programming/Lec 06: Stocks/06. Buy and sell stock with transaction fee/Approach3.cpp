class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j==1)  dp[i][j] = max((0+dp[i+1][j]),(-v[i]+dp[i+1][1-j]));

                else        dp[i][j] = max((0+dp[i+1][j]),(v[i]+dp[i+1][1-j]-fee));
            }
        }

        return dp[0][1];
    }
};
