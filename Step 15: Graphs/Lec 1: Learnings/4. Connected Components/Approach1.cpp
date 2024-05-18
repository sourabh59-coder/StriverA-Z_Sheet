#include <bits/stdc++.h>
#define int long long
using namespace std;

int NumberOfComponents(vector<int> adj[],int n,vector<int> &vis)
{
    queue<int> qe;
    int cnt = 0;
    
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            qe.push(i);
            vis[i] = 1;
            cnt++;
            
            while(!qe.empty())
            {
                int node = qe.front();
                qe.pop();
                
                for(auto child: adj[node])
                {
                    if(!vis[child])
                    {
                        qe.push(child);
                        vis[child] = 1;
                    }
                }
            }
        }
    }
    
    return cnt;
}

signed main()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(n+1,0);
    int no_of_components = NumberOfComponents(adj,n,vis);
    
    cout<<"Number of components of the graphs: - "<<no_of_components<<endl;
    
    return 0;
}
