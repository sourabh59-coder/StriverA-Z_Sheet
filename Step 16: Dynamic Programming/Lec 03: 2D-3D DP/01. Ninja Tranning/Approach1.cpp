int fun(vector<vector<int>>& v,int ind,int n,int prev)
    {
        if(ind==n)  return 0;
        
        int ans = 0;
        
        for(int i=0;i<=2;i++)
        {
            if(i!=prev)
            {
                int val = v[ind][i] + fun(v,ind+1,n,i);
                ans = max(ans , val);
            }
        }
        
        return ans;
    }
    int maximumPoints(vector<vector<int>>& v, int n) {
        // Code here
        return fun(v,0,n,3);
    }
