class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,int buy,vector<vector<vector<int>>> &dp)
    {
        if(ind==n)  return dp[ind][k][buy] = 0;
        
        if(k==0)    return dp[ind][k][buy] = 0;

        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy];

        if(buy==1)  return dp[ind][k][buy] = max((0+fun(v,ind+1,n,k,buy,dp)),(-v[ind]+fun(v,ind+1,n,k,1-buy,dp)));

        else    return dp[ind][k][buy] = max((0+fun(v,ind+1,n,k,buy,dp)),(v[ind]+fun(v,ind+1,n,k-1,1-buy,dp)));
    }
    int maxProfit(int k, vector<int>& v) {
        int n = v.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (k+1, vector<int> (2,-1)));
        return fun(v,0,n,k,1,dp);
    }
};
