class Solution {
public:
    int fun(vector<int> &v,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j) return 0;

        if(dp[i][j]!=-1)    return dp[i][j];

        int ans = INT_MIN;
        for(int k=i;k<=j;k++)
        {
            int val = v[i-1]*v[k]*v[j+1] + fun(v,i,k-1,dp) + fun(v,k+1,j,dp);
            ans = max(ans,val);
        }

        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& v) {
        v.push_back(1);
        v.insert(v.begin(),1);
        int n = v.size();
        int i = 1;
        int j = n-2;

        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));

        return fun(v,i,j,dp);
    }
};
