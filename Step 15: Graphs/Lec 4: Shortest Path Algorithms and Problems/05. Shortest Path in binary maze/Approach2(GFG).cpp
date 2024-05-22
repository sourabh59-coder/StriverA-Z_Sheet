vector<pair<int,int>> moments = {{1,0},{0,1},{0,-1,},{-1,0}};
    int shortestPath(vector<vector<int>> &v, pair<int, int> src, pair<int, int> des) {
        if(v[src.first][src.second]==0) return -1;
        
        int n = v.size();
        int m = v[0].size();
        vector<vector<int>> ans(n, vector<int> (m,-1));
        queue<pair<int,int>> qe;
        
        int cnt = 0;
        qe.push({src.first,src.second});
        ans[src.first][src.second] = 0;
        
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            
            for(int i=0;i<si;i++)
            {
                auto it = qe.front();
                qe.pop();
                
                int par_x = it.first;
                int par_y = it.second;
                
                for(auto moment: moments)
                {
                    int x = par_x + moment.first;
                    int y = par_y + moment.second;
                    
                    if(x>=0 && y>=0 && x<n && y<m && ans[x][y]==-1 && v[x][y]==1)
                    {
                        ans[x][y] = cnt;
                        qe.push({x,y});
                    }
                }
            }
        }
        
        return ans[des.first][des.second];
    }
