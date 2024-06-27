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

        int getSize(int node) {
            int ulp = findUPar(node);
            return size[ulp];
        }
}; 

class Solution {
public:
    int getDsuInd(int i,int j,int n)
    {
        return (i*(n) + j);
    }
    vector<pair<int,int>> moments = {{1,0},{0,1},{-1,0},{0,-1}};
    bool isValid(int x,int y,int n)
    {
        return (x>=0 && y>=0 && x<n && y<n);
    }
    int largestIsland(vector<vector<int>>& v) {
        int n = v.size();

        DisjointSet ds(n*n);

        int ans = INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int ind = getDsuInd(i,j,n);

                if(v[i][j]==1)
                {
                    for(auto moment: moments)
                    {
                        int x = moment.first + i;
                        int y = moment.second + j;

                        if(isValid(x,y,n))
                        {
                            if(v[x][y]==1)
                            {
                                int child_ind = getDsuInd(x,y,n);
                                ds.unionBySize(child_ind,ind);
                            }
                        }
                    }
                }

                int si = ds.getSize(ind);
                ans = max(ans,si);
            }
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                set<int> st;
                if(v[i][j]==0)
                {
                    int ind = getDsuInd(i,j,n);

                    int check = 1;

                    for(auto moment: moments)
                    {
                        int x = moment.first + i;
                        int y = moment.second + j;

                        if(isValid(x,y,n))
                        {
                            if(v[x][y]==1)
                            {
                                int child_ind = getDsuInd(x,y,n);
                                st.insert(ds.findUPar(child_ind));
                            }
                        }
                    }

                    for(auto it: st)
                    {
                        int si = ds.getSize(it);
                        check += si;
                    }

                    ans = max(ans,check);
                }
            }
        }

        return ans;
    }
};
