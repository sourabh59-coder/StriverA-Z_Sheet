string findOrder(string v[], int n, int k) {
        vector<int> adj[k];
        for(int i=0;i<n-1;i++)
        {
            string a = v[i];
            string b = v[i+1];
            
            int si =  min(a.size(),b.size());
            for(int i=0;i<si;i++)
            {
                if(a[i]!=b[i])
                {
                    int u = a[i]-'a';
                    int v = b[i]-'a';
                    
                    // cout<<u<<" "<<v<<endl;
                    
                    adj[u].push_back(v);
                    
                    break;
                }
            }
        }
        
        // cout<<"next"<<endl;
            
            vector<int> ans;
            queue<int> qe;
            vector<int> wt(k,0);
            
            for(int i=0;i<k;i++)
            {
                // cout<<i<<" :- ";
                for(auto it: adj[i])
                {
                    // cout<<it<<" ";
                    wt[it]++;
                }
                // cout<<endl;
            }
            // cout<<endl;
            
            for(int i=0;i<k;i++)    if(wt[i]==0)    qe.push(i);
            
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
            
            string final = "";
            for(int i=0;i<ans.size();i++)
            {
                char ch = 'a'+ans[i];
                final += ch;
            }
            // cout<<final<<endl;
            return final;
    }
