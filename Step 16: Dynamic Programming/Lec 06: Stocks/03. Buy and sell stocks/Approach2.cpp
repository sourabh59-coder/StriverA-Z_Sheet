class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,int k, vector<vector<vector<int>>> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];

        if(k>0)
        {
            if(buy==1)
            {
                return dp[ind][buy][k] = max((0+fun(v,ind+1,n,buy,k,dp)),(-v[ind]+fun(v,ind+1,n,1-buy,k,dp)));
            }

            else
            {
                return dp[ind][buy][k] = max((0+fun(v,ind+1,n,buy,k,dp)),(v[ind]+fun(v,ind+1,n,1-buy,k-1,dp)));
            }
        }

        return dp[ind][buy][k] = 0;
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2 , vector<int> (3,-1)));
        return fun(v,0,n,1,k,dp);
    }
};
