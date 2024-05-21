vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> topo_sort;
	    queue<int> qe;
	    vector<int> wt(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        {
	           // cout<<it<<" ";
	            wt[it]++;
	        }
	       // cout<<endl;
	    }
	   // cout<<endl;
	    
	    for(int i=0;i<wt.size();i++)
	    {
	        if(wt[i]==0)    qe.push(i);
	    }
	    
	    while(!qe.empty())
	    {
	        auto node = qe.front();
	        qe.pop();
	        topo_sort.push_back(node);
	        
	        for(auto child: adj[node])
	        {
	            wt[child]--;
	            if(wt[child]==0)
	            {
	                qe.push(child);
	            }
	        }
	    }
	    
	   // for(int i=0;i<topo_sort.size();i++) cout<<topo_sort[i]<<" ";
	   // cout<<endl;
	    
	    return topo_sort;
	}
