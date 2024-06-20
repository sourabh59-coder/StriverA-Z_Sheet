class Solution {
public:
    int fun(vector<int> &v,int i,int j)
    {
        if(i>j) return 0;

        int ans = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int val = v[i-1]*v[k]*v[j+1] + fun(v,i,k-1) + fun(v,k+1,j);
            ans = max(ans,val);
        }

        return ans;
    }
    int maxCoins(vector<int>& v) {
        v.push_back(1);
        v.insert(v.begin(),1);
        int n = v.size();
        int i = 1;
        int j = n-2;

        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<=n-2;j++)
            {
                // if(i>j) dp[i][j] = 1;
                int ans = INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int val = v[i-1]*v[k]*v[j+1] + dp[i][k-1] + dp[k+1][j];
                    ans = max(ans,val);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n-2];
        // return fun(v,i,j);
    }
};
