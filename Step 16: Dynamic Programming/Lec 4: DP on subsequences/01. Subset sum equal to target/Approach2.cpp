int fun(vector<int> v,int ind,int n,int sum, vector<vector<int>> &dp)
    {
        if(sum==0)  return 1;
        
        if(ind==n)  return 0;
        
        if(dp[ind][sum]!=-1)    return dp[ind][sum];
        
        bool notTake = fun(v,ind+1,n,sum,dp);
        
        bool Take = 0;
        
        if(v[ind] <= sum)   Take = fun(v,ind+1,n,sum-v[ind],dp);
        
        return dp[ind][sum] = (Take | notTake);
    }
    bool isSubsetSum(vector<int>v, int sum){
        int n = v.size();
        vector<vector<int>> dp(n+1, vector<int> (sum+1,-1));
        return fun(v,0,n,sum,dp); 
    }
