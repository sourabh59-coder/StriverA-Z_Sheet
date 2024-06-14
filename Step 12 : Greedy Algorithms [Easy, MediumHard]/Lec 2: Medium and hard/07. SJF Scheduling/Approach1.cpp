//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& v) {
        // code here
        int n = v.size();
        sort(v.begin(),v.end());
        long long start = 0;
        long long wt = 0; 
        for(int i=0;i<n;i++)
        {
            wt += (start-0);
            start += v[i];
        }
        wt = (long long)wt / (long long)n;
        return wt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> bt(n), p(n);
        for (int i = 0; i < n; i++) {
            cin >> bt[i];
        }
        Solution obj;
        long long ans = obj.solve(bt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
