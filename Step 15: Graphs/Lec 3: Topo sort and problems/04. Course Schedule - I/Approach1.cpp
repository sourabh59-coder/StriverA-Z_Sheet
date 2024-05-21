class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        int m = v.size();
        vector<int> adj[n];
        for(int i=0;i<m;i++)
        {
            int a = v[i][0];
            int b = v[i][1];
            
            adj[a].push_back(b);
        }
        vector<int> ans;
        queue<int> qe;
        vector<int> wt(n,0);
        
        for(int i=0;i<n;i++)
        {
            for(auto it: adj[i])
            {
                wt[it]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(wt[i]==0)    qe.push(i);
        }
        
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
        
        return ((ans.size()==n) ? true : false);
    }
};
