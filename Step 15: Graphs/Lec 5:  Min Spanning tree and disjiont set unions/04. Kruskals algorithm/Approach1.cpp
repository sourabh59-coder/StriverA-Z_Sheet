int parent[10001];
	int size[10001];
	
	int make(int v)
	{
	    parent[v] = v;
	    size[v] = 1;
	}
	
	int find(int v)
	{
	    if(parent[v] == v)  return v;
	    return parent[v] = find(parent[v]);
	}
	
	 void Union(int x, int y)
	 {
	     int a = find(x);
	     int b = find(y);
	     
	     if(a!=b)
	     {
	         if(size[a]<size[b])    swap(a,b);
	         
	         parent[b] = a;
	         size[a] += size[b];
	     }
	 }
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<V;i++)
        {
            for (auto &neighbor : adj[i]) {
                int x = i;
                int y = neighbor[0];
                int wt = neighbor[1];
                
                make(x);
                make(y);
                
                v.push_back({wt, {x, y}});
            }
        }
        
        sort(v.begin(),v.end());
        
        int ans = 0;
        vector<pair<int,int>> vec;
        for(int i=0;i<v.size();i++)
        {
            int wt = v[i].first;
            int x = v[i].second.first;
            int y = v[i].second.second;
            
            int a = find(x);
            int b = find(y);
            
            if(a==b)    continue;
            
            ans += wt;
            vec.push_back({x,y});
            Union(a,b);
        }
        
        // for(int i=0;i<vec.size();i++)   cout<<vec[i].first<<" "<<vec[i].second<<endl;
        
        return ans;
    }
