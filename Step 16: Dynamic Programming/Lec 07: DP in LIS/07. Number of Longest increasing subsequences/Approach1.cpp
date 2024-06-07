class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> cnt(n,1);
        vector<int> dp(n,1);

        int ans = 0;
        int max_len = 1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j] < v[i])
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1)
                    {
                        cnt[i] += cnt[j];
                    }
                }
            }
            max_len = max(max_len,dp[i]);
        }

        for(int i=0;i<n;i++)
        {
            if(dp[i]==max_len)  ans += cnt[i];
        }


        // for(int i=0;i<n;i++)    cout<<cnt[i]<<" ";
        // cout<<endl;

        // for(int i=0;i<n;i++)    cout<<dp[i]<<" ";
        // cout<<endl;

        return ans;
    }
};
