// int fun(vector<int> &v,int ind,int k)
    // {
    //     if(k==0)    return true;
    //     if(ind<0)   return false;

    //     int notTake = fun(v,ind-1,k);
    //     int Take = 0;
    //     if(k>=v[ind])   Take = fun(v,ind-1,k-v[ind]);

    //     return (Take | notTake);
    // }
    vector<int> TargetSumTabulation(vector<int> &v,int n,int k)
    {
        // vector<vector<int>> dp(n+1, vector<int> (k+1,0));
        vector<int> prev(k+1,0);
        vector<int> curr(k+1,0);

        // for(int i=0;i<=n;i++)   dp[i][0] = 1;
        prev[0] = 1;
        curr[0] = 1;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                int notTake = prev[j];

                int Take = 0;

                if(j>=v[i-1])   Take = prev[j-v[i-1]];

                curr[j] = (Take | notTake);
            }
            prev = curr;
        }

        return curr;
    }

int minSubsetSumDifference(vector<int>& v, int n)
{
	// Write your code here.
    int sum = 0;
    for(int i=0;i<n;i++)    sum += v[i];
    vector<int> curr = TargetSumTabulation(v,n,sum);
	int ans = INT_MAX;
	for(int i=0;i<curr.size();i++)
	{	
		if(curr[i]) ans = min(ans,abs(sum-(2*i)));
	}
	return ans;
}
