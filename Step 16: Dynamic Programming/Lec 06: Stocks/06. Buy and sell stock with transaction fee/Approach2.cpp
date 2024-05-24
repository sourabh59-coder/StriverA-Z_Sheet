class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,int fee,vector<vector<int>> &dp)
    {
        if(ind==n)  return dp[ind][buy] = 0;

        if(dp[ind][buy]!=-1)    return dp[ind][buy];

        if(buy==1)  return dp[ind][buy] = max((0+fun(v,ind+1,n,buy,fee,dp)),(-v[ind]+fun(v,ind+1,n,1-buy,fee,dp)));

        else        return dp[ind][buy] = max((0+fun(v,ind+1,n,buy,fee,dp)),(v[ind]+fun(v,ind+1,n,1-buy,fee,dp)-fee));
    }
    int maxProfit(vector<int>& v, int fee) {
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (2,-1));
        return fun(v,0,n,1,fee,dp);
    }
};
