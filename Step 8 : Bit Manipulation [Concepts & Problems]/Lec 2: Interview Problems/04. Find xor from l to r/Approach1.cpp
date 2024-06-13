//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int xoring(int x)
    {
        if(x % 4 == 1)return 1;
        else if(x % 4 == 2)return x+1;
        else if(x % 4 == 3)return 0;
        else return x;
    }
    int findXOR(int l, int r) {
        return xoring(r)^xoring(l-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends
