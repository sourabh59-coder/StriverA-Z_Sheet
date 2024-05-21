class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> wt(n,0);
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            {
                wt[i]++;
                adj[it].push_back(i);
            }
        }
        
        queue<int> qe;
        for(int i=0;i<n;i++)    if(wt[i]==0)    qe.push(i);
        
        // for(int i=0;i<n;i++)    cout<<wt[i]<<" ";
        // cout<<endl;
        
        while(!qe.empty())
        {
            auto node = qe.front();
            qe.pop();
            
            ans.push_back(node);
            
            for(auto it: adj[node])
            {
                wt[it]--;
                if(wt[it]==0)   qe.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
