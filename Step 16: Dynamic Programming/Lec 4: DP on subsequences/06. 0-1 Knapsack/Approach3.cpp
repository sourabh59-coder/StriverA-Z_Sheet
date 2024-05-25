int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    //   return fun(wt,val,0,n,W,dp);
    
    vector<int> curr(W+1, 0);
    vector<int> next(W+1, 0);
      
      for(int i=n-1;i>=0;i--)
      {
          for(int j=0;j<=W;j++)
          {
              int notTake = 0 + next[j];
              
              int Take = 0;
              
              if(wt[i]<=j)  Take = val[i] + next[j-wt[i]];
              
              curr[j] = max(Take, notTake);
          }
          
          next = curr;
      }
      
      return curr[W];
    }
