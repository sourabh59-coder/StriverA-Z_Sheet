int totalFruits(int N, vector<int> &v) {
        pair<int,int> a(-1,-1),b(-1,-1);
        int ans = 0;
        int left = 0;
        
        for(int i=0;i<N;i++)
        {
            if(a.first==v[i])
            {
                a.second = i;
            }
            else if(b.first==v[i])
            {
                b.second = i;
            }
            else if(a.first==-1)
            {
                a.first = v[i];
                a.second = i;
            }
            else if(b.first==-1)
            {
                b.first = v[i];
                b.second = i;
            }
            else
            {
                if(a.second>=b.second)
                {
                    left = b.second+1;
                    b.first = v[i];
                    b.second = i;
                }
                else
                {
                    left = a.second+1;
                    a.first = v[i];
                    a.second = i;
                }
            }
            
            ans = max(ans,i-left+1);
        }
        
        return ans;
    }
