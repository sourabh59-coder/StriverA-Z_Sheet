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
    vector<vector<string>> accountsMerge(vector<vector<string>>& v) {
        map<string,int> mp;
        int n = v.size();
        DisjointSet ds(n);

        for(int i=0;i<n;i++)
        {
            int m = v[i].size();
            for(int j=1;j<m;j++)
            {
                if(mp.count(v[i][j])==0)
                {
                    mp[v[i][j]] = i;
                }
                else
                {
                    ds.unionBySize(mp[v[i][j]],i);
                }
            }
        }

        vector<string> vec[n];
        for(auto it: mp)
        {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            vec[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++)
        {
            if(vec[i].size()==0)    continue;

            vector<string> temp;
            temp.push_back(v[i][0]);
            sort(vec[i].begin(),vec[i].end());
            for(auto it: vec[i])
            {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
