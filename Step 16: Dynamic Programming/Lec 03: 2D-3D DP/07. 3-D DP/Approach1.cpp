int fun(vector<vector<int>> &v,int i,int j1,int j2,int n,int m)
    {
        if(j1<0 || j1>=m || j2<0 || j2>=m)     return -1e9;
        if(i==n-1)
        {
            if(j1==j2)  return (v[i][j1]);
            else        return (v[i][j1] + v[i][j2]);
        }
        // if(i==n)    return  0;
        
        int maxi = -1e9;
        
        for(int j=-1;j<=1;j++)
        {
            for(int k=-1;k<=1;k++)
            {
                if(j1==j2)  maxi = max(maxi , v[i][j1] + fun(v,i+1,j1+j,j2+k,n,m));
                else        maxi = max(maxi , v[i][j1] + v[i][j2] + fun(v,i+1,j1+j,j2+k,n,m));
            }
        }
        
        return maxi;
    }
    int solve(int n, int m, vector<vector<int>>& v) {
        // code here
        return fun(v,0,0,m-1,n,m);
    }
