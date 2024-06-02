int solve(int n, int m, vector<vector<int>>& v) {
        // code here
        // vector<vector<vector<int>>> dp(n, vector<vector<int>> (m, vector<int> (m,-1e9)));
        vector<vector<int>> curr(m, vector<int> (m,-1e9)), next(m, vector<int> (m,-1e9));
        
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(j==k)    next[j][k] = v[n-1][j];
                else        next[j][k] = v[n-1][j] + v[n-1][k];
            }
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=m-1;j1>=0;j1--)
            {
                for(int j2=0;j2<m;j2++)
                {
                    int maxi = -1e9;
                    for(int j=-1;j<=1;j++)
                    {
                        for(int k=-1;k<=1;k++)
                        {
                            int value = 0;
                            if(j1==j2)  value += v[i][j1];
                            else        value += (v[i][j1] + v[i][j2]);
                            
                            if((j1+j)>=0 && (j1+j)<m && (j2+k)>=0 && (j2+k)<m)  value += next[j1+j][j2+k];
                            else                                                value += -1e9;
                            
                            maxi = max(maxi,value);
                        }
                    }
                    
                    curr[j1][j2] = maxi;
                }
            }
            
            next = curr;
        }
        
        
        return curr[0][m-1];
        // return fun(v,0,0,m-1,n,m,dp);
    }
