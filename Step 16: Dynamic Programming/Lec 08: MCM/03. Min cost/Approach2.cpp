class Solution {
public:
    int fun(vector<int> &v,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        int ans = INT_MAX;

        for(int k=i;k<=j;k++)
        {
            int val = v[j+1]-v[i-1] + fun(v,i,k-1,dp) + fun(v,k+1,j,dp);

            ans = min(val,ans);
        }

        return dp[i][j] = ans;
    }
    int minCost(int n, vector<int>& v) {
        v.push_back(0);
        v.push_back(n);
        sort(v.begin(),v.end());
        n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,-1));
        return fun(v,1,n-2,dp);
    }
};
