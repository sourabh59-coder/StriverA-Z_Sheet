//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& v, int start, int end) {
        // code here
        int n = v.size();
        vector<int> dist(100000,1e9);
        queue<pair<int,int>> qe;
        
        qe.push({0,start});
        dist[start] = 0;
        
        while(!qe.empty())
        {
            auto it = qe.front();
            qe.pop();
            
            int node = it.second;
            int cnt  = it.first;
            
            if(node==end)   return cnt;
            
            for(int i=0;i<v.size();i++)
            {
                int ind = ( node * v[i] ) % 100000;
                // qe.push({cnt+1,val});
                
                if(dist[ind] > cnt+1)
                {
                    dist[ind] = cnt+1;
                    qe.push({cnt+1,ind});
                }
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends
