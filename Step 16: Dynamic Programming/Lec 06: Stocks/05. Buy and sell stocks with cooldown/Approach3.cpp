class Solution {
public:
    int maxProfit(vector<int>& v) {
        int n = v.size();
        vector<vector<int>> dp(n+3, vector<int> (2,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(j)     dp[i][j] = max((0+dp[i+1][j]),(-v[i]+dp[i+1][1-j]));

                else       dp[i][j] = max((0+dp[i+1][j]),(+v[i]+dp[i+2][1-j]));
            }
        }

        return dp[0][1];
    }
};
