int fun(vector<int> &v,int ind,int n,int k,vector<vector<int>> &dp)
{
    if(ind==n)
    {
        if(k==0)    return 1;
        else        return 0;
    }

    if(dp[ind][k]!=-1)  return dp[ind][k];

    int notTake = 0, Take = 0;

    notTake = fun(v,ind+1,n,k,dp);

    if(v[ind] <= k) Take = fun(v,ind+1,n,k-v[ind],dp);

    return dp[ind][k] = (Take || notTake);
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    vector<vector<int>> dp(n+1, vector<int> (k+1,-1));
    return fun(a,0,n,k,dp);
}
