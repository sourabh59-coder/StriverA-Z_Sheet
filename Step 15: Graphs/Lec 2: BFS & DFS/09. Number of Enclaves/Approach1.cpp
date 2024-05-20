class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{0,-1},{-1,0}};
    int numEnclaves(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        queue<pair<int,int>> qe;
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && v[i][j]==1)
                {
                    qe.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            int x_c = node.first;
            int y_c = node.second;
            
            for(auto moment: moments)
            {
                int x = x_c + moment.first;
                int y = y_c + moment.second;
                
                if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && v[x][y]==1)
                {
                    vis[x][y] = 1;
                    qe.push({x,y});
                }
            }
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && v[i][j]==1)    ans++;
            }
        }
        
        return ans;
    }
};
