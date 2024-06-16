class Solution {
public:
    int countPrimes(int n) {
        vector<int> dp(n+1,1);
        if(n==0 || n==1)    return 0;
        dp[0] = 0;
        if(n>=1)    dp[1] = 0;
        for(int i=2;i*i<=n;i++)
        {
            if(dp[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    dp[j] = 0;
                }
            }
        }
        int cnt= 0;
        for(int i=2;i<n;i++)
        {
            if(dp[i])    cnt++;
        }
        return cnt;
    }
};
