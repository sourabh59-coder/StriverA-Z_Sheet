class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& adj, int thres) {
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));
        for(int i=0;i<n;i++)    dist[i][i] = 0;
        for(int i=0;i<adj.size();i++)
        {
            dist[adj[i][0]][adj[i][1]] = adj[i][2]; 
            dist[adj[i][1]][adj[i][0]] = adj[i][2]; 
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)  continue;
                    dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
                }
            }
        }

        int cityNo = -1;
        int count = n;

        for(int i=0;i<n;i++)
        {
            int cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=thres)   cnt++;
            }
            if(cnt<=count)
            {
                count = cnt;
                cityNo = i;
            }
        }

        return cityNo;
    }
};
