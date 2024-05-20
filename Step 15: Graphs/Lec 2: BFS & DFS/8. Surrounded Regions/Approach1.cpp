class Solution {
public:
    vector<pair<int,int>> moments = {
        {1,0},{0,1},{0,-1},{-1,0}
    };
    void solve(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        queue<pair<int,int>> qe;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i==n-1 || j==m-1) && (v[i][j]=='O'))
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
                int x = x_c+moment.first;
                int y = y_c+moment.second;
                
                if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && v[x][y]=='O')
                {
                    vis[x][y] = 1;
                    qe.push({x,y});
                }
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((!vis[i][j]) && (v[i][j]=='O'))
                {
                    v[i][j] = 'X';
                }
            }
        }
    }
};
