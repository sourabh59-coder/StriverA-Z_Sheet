int mod = 1000000007;
    int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            if(k==0)    return 1;
            else    return 0;
        }
        
        if(dp[ind][k]!=-1)      return dp[ind][k];
        
        int notTake = fun(v,ind+1,n,k,dp);
        
        int Take = 0;
        
        if(v[ind] <= k)     Take = fun(v,ind+1,n,k-v[ind],dp);
        
        return dp[ind][k] = (notTake + Take) % mod;
    }
    int countPartitions(int n, int d, vector<int>& v) {
        // Code here
        int s = 0;
        for(int i=0;i<n;i++)    s += v[i];
        if((d+s)%2!=0)  return 0;    
        int k = (s+d)/2;
        vector<vector<int>> dp(n, vector<int> (k+1, -1));
        return fun(v,0,n,k,dp);
    }
