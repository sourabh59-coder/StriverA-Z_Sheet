class Solution {
public:
    // int fun(vector<int> &v,int i,int j)
    // {
    //     if(i>j) return 0;

    //     int ans = INT_MAX;

    //     for(int k=i;k<=j;k++)
    //     {
    //         int val = v[j+1]-v[i-1] + fun(v,i,k-1) + fun(v,k+1,j);

    //         ans = min(val,ans);
    //     }

    //     return dp[i][j];
    // }
    int minCost(int n, vector<int>& v) {
        v.push_back(0);
        v.push_back(n);
        sort(v.begin(),v.end());
        n = v.size();
        // return fun(v,1,n-2);
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int i=n-2;i>=1;i--)
        {
            for(int j=i;j<=n-2;j++)
            {
                int ans = INT_MAX;

                for(int k=i;k<=j;k++)
                {
                    int val = (v[j+1]-v[i-1]) + dp[i][k-1] + dp[k+1][j];

                    ans = min(val,ans);
                }

                dp[i][j] = ans;
            }
        }
        return dp[1][n-2];
    }
};
