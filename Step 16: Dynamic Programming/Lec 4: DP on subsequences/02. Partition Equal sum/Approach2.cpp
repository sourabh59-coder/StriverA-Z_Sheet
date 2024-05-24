class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int sum, vector<vector<int>> &dp)
    {
        if(sum==0)  return 1;

        if(ind==n)  return 0;

        if(dp[ind][sum]!=-1)    return dp[ind][sum];

        int notTake = fun(v,ind+1,n,sum,dp);

        int Take = 0;

        if(v[ind] <= sum)   Take = fun(v,ind+1,n,sum-v[ind],dp);

        return dp[ind][sum] = (notTake | Take);
    }
    bool canPartition(vector<int>& v) {
        int sum(0);
        for(int i=0;i<v.size();i++)     sum += v[i];
        if(sum%2!=0)    return false;

        // cout<<sum<<endl;

        sum = sum/2;
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1, -1));
        return fun(v,0,n,sum,dp);
    }
};
