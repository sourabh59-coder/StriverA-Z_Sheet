class Solution {
public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
        int n = v.size();
        if(v[0][0]!=0 || v[n-1][n-1]!=0)
        {
            return -1;
        }
        
        vector<vector<int>> vis(n, vector<int> (n,0));
        queue<pair<int,int>> qe;
        qe.push({0,0});
        vis[0][0] = 1;
        int cnt = 0;
        
        while(!qe.empty())
        {
            int si = qe.size();
            cnt++;
            for(int i=0;i<si;i++)
            {
                auto node = qe.front();
                qe.pop();
                
                int x_par = node.first;
                int y_par = node.second;
                
                for(auto moment: moments)
                {
                    int x = moment.first+x_par;
                    int y = moment.second+y_par;
                    
                    if(x>=0 && y>=0 && x<n && y<n && !vis[x][y] && v[x][y]==0)
                    {
                        vis[x][y] = 1;
                        v[x][y] = cnt;
                        qe.push({x,y});
                    }
                }
            }
        }
        
        if(!vis[n-1][n-1])  return -1;
        else    return v[n-1][n-1]+1;
    }
};
