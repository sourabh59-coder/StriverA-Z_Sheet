class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,vector<vector<int>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        if(buy)
        {
            return dp[ind][buy] = max( 0+fun(v,ind+1,n,1,dp) , -v[ind]+fun(v,ind+1,n,0,dp));
        }

        else
        {
            return dp[ind][buy] = max( 0+fun(v,ind+1,n,0,dp) , v[ind]+fun(v,ind+1,n,1,dp));
        }
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        bool buy = true;
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return fun(v,0,n,1,dp);
    }
};
