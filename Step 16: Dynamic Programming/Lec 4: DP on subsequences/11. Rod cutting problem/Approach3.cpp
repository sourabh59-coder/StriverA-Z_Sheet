int cutRod(int v[], int n) {
        int w = n;
        vector<vector<int>> dp(n+2, vector<int> (w+1, 0));
        // return fun(price,1,n,w,dp);
        vector<int> curr(w+1,0);
        vector<int> next(w+1,0);
        
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=w;j++)
            {
                int notTake = 0 + next[j];
                
                int Take = 0;
                
                if(j >= i)  Take = v[i-1] + curr[j-i];
                
                curr[j] = max(Take, notTake);
            }
            
            next = curr;
        }
        
        return curr[w];
    }
