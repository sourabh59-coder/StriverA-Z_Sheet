//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer = 1;
    void dfs(int node,int parent,vector<int> adj[],int low[],int tin[],vector<int> &vis,vector<int> &mark)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        int child_cnt = 0;
        
        for(auto it:adj[node])
        {
            if(it==parent)  continue;
            if(vis[it]==0)
            {
                dfs(it,node,adj,low,tin,vis,mark);
                low[node] = min(low[node],low[it]);
                if(low[it]>=tin[node] && parent!=-1)
                {
                    mark[node] = 1;
                }
                child_cnt++;
            }
            else
            {
                low[node] = min(low[node],tin[it]);
            }
        }
        
        if(child_cnt>1 && parent==-1)   mark[node] = 1;
    }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        // Code here
        vector<int> ans;
        vector<int> mark(n,0);
        vector<int> vis(n,0);
        int low[n];
        int tin[n];
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,low,tin,vis,mark);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mark[i]) ans.push_back(i);
        }
        if(ans.size()==0)   ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
