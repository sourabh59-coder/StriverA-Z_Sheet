int fun(vector<vector<int>> &v,int n,int prev)
    {
        if(n==0)
        {
            int maxi = 0;
            
            for(int i=0;i<3;i++)
            {
                if(prev!=i)     maxi = max(maxi,v[n][i]);
            }
            
            return maxi;
        }
        
        int maxi = 0;
        
        for(int i=0;i<3;i++)
        {
            if(prev!=i)
            {
                int val = v[n][i] + fun(v,n-1,i);
                
                maxi = max(maxi , val);
            }
        }
        
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        return fun(points,n-1,3);
    }
