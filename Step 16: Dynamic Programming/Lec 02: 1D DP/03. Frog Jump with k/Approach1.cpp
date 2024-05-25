int fun(vector<int> &v,int ind,int n,int k)
    {
        if(ind==n-1)    return 0;
        
        int ans = INT_MAX;
        
        for(int i=1;i<=k;i++)
        {
            if(n-1-i >= ind)  ans = min(ans, fun(v,ind+i,n,k) + abs(v[ind] - v[ind+i]));
        }
        
        return ans;
    }
    int minimizeCost(vector<int>& v, int n, int k) {
        // Code here
        return fun(v,0,n,k);
    }
