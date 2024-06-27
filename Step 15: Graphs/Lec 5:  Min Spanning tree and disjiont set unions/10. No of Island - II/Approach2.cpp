//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size; 
    public: 
        DisjointSet(int n) {
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1); 
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
                size[i] = 1; 
            }
        }
    
        int findUPar(int node) {
            if(node == parent[node])
                return node; 
            return parent[node] = findUPar(parent[node]); 
        }
    
        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return; 
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v; 
            }
            else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u; 
            }
            else {
                parent[ulp_v] = ulp_u; 
                rank[ulp_u]++; 
            }
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return; 
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }
}; 

class Solution {
  public:
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& v) {
        vector<int> ans;
        DisjointSet ds(m * n);
        vector<vector<int>> check(n, vector<int>(m, 0));
        int cnt = 0;
        
        for (auto it : v) {
            if(check[it[0]][it[1]]==1)
            {
                ans.push_back(cnt);
                continue;
            }
            check[it[0]][it[1]] = 1;
            int dsu_no_par = (it[0] * m) + it[1];
            cnt++;
            
            for (auto moment : moments) {
                int x = moment.first + it[0];
                int y = moment.second + it[1];
                
                if (x >= 0 && y >= 0 && x < n && y < m && check[x][y] == 1) {
                    int dsu_no_child = (x * m) + y;
                    
                    if (ds.findUPar(dsu_no_child) != ds.findUPar(dsu_no_par)) {
                        cnt--;
                        ds.unionBySize(dsu_no_child, dsu_no_par);
                    }
                }
            }
            
            ans.push_back(cnt); // size of dsu
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends
