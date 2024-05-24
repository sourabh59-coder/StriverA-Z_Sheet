class Solution {
public:
    bool canPartition(vector<int>& v) {
        int sum(0);
        for(int i=0;i<v.size();i++)     sum += v[i];
        if(sum%2!=0)    return false;

        // cout<<sum<<endl;

        sum = sum/2;
        int n = v.size();
        // vector<vector<int>> dp(n+1, vector<int> (sum+1, 0));
        vector<int> curr(sum+1,0);
        vector<int> next(sum+1,0);
        
        // for(int i=0;i<=n;i++)   dp[i][0] = 1;

        curr[0] = 1;
        next[0] = 1;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=1;j<=sum;j++)
            {
                int notTake = next[j];

                int Take = 0;

                if(v[i] <= j)   Take = next[j-v[i]];

                curr[j] = (notTake | Take);
            }

            next = curr;
        }

        return curr[sum];
    }
};
