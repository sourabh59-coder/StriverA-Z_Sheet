class Solution {
public:
    vector<pair<int,int>> moments = {
        {0,1},{1,0},{-1,0},{0,-1}
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        
        queue<pair<int,int>> qe;
        int wt = 0;
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j]==0)
                {
                    qe.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!qe.empty())
        {
            wt++;
            int si = qe.size();
            
            for(int i=0;i<si;i++)
            {
                auto node = qe.front();
                qe.pop();
                
                int x_c = node.first;
                int y_c = node.second;
                
                for(auto moment: moments)
                {
                    int x = x_c+moment.first;
                    int y = y_c+moment.second;
                    
                    if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && v[x][y]==1)
                    {
                        vis[x][y] = 1;
                        v[x][y] = wt;
                        qe.push({x,y});
                    }
                }
            }
        }
        
        return v;
    }
};
