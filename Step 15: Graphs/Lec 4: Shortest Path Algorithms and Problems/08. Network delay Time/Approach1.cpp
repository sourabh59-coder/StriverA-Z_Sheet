class Solution {
public:
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<v.size();i++)
        {
            int u1 = v[i][0];
            int v1 = v[i][1];
            int wt = v[i][2];
            
            adj[u1].push_back({v1,wt});
        }
        
        vector<int> ans(n+1,1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        
        ans[k] = 0;
        qe.push({0,k});
        
        while(!qe.empty())
        {
            auto node = qe.top();
            qe.pop();
            
            int wt = node.first;
            int ind = node.second;
            
            for(auto it: adj[ind])
            {
                int child_wt = it.second;
                int child_ind = it.first;
                
                if(child_wt+wt < ans[child_ind])
                {
                    ans[child_ind] = wt + child_wt;
                    qe.push({ans[child_ind],child_ind});
                }
            }
        }
        
        int cnt = 0;
        for(int i=1;i<ans.size();i++)
        {
            cnt = max(cnt,ans[i]);
        }
        
        return (cnt==1e9) ? -1 : cnt;
    }
};
