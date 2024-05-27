int longestSubsequence(int n, int v[])
    {
       // your code here
       vector<int> ans;
       
       for(int i=0;i<n;i++)
       {
           if(ans.size()==0)
           {
               ans.push_back(v[i]);
           }
           else if(ans.back() < v[i])
           {
               ans.push_back(v[i]);
           }
           else
           {
               int ind = lower_bound(ans.begin() , ans.end(), v[i]) - ans.begin();
               
               ans[ind] = v[i];
           }
       }
       
       return ans.size();
    }
