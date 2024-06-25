class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int k,vector<int> &dp)
    {
        if(ind==n)  return 0;

        if(dp[ind]!=-1) return dp[ind];

        int ans = INT_MIN;
        int maxi = INT_MIN;
        int len = 0;
        for(int i=ind;i<min(n,ind+k);i++)
        {
            len++;
            maxi = max(maxi,v[i]);
            int val = (maxi*len) + fun(v,i+1,n,k,dp);
            ans = max(ans,val);
        }
        return dp[ind] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n+1,-1);
        return fun(v,0,n,k,dp);
    }
};
