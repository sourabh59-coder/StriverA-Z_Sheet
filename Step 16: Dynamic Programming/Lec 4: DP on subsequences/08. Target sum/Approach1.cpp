class Solution {
public:
    vector<int> TargetSumTabulation(vector<int> &v,int n,int k)
    {
        // vector<vector<int>> dp(n+1, vector<int> (k+1,0));
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);

        // for(int i=0;i<=n;i++)   dp[i][0] = 1;
        prev[0] = 1;
        curr[0] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int notTake = prev[j];

                int Take = 0;

                if(j>=v[i-1])   Take = prev[j-v[i-1]];

                curr[j] = (Take + notTake);
            }
            prev = curr;
        }

        return curr;
    }
    int findTargetSumWays(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0;
        for(int i=0;i<n;i++)    sum += v[i];
        vector<int> curr = TargetSumTabulation(v,n,sum);
        int ans = 0;
        for(int i=0;i<curr.size();i++)
        {
            cout<<curr[i]<<" ";
            if(curr[i]!=0)
            {
                int val = (sum - (2*i));
                if(val==k) ans += curr[i];
            }
        }
        cout<<endl;
        return ans;
    }
};
