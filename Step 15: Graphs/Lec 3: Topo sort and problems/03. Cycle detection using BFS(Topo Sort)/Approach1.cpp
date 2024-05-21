public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> ans;
        queue<int> qe;
        vector<int> wt(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                wt[it]++;
            }
        }
        
        for(int i=0;i<V;i++)    if(wt[i]==0)    qe.push(i);
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            ans.push_back(node);
            
            for(auto child: adj[node])
            {
                wt[child]--;
                if(wt[child]==0)    qe.push(child);
            }
        }
        
        return (ans.size()==V ? false:true);
    }
