//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int n) {

        // Write your code here
        vector<int> prime(n+1,1);
        for(int i=1;i<=n;i++)   prime[i] = i;
        
        for(int i=2;i*i<=n;i++)
        {
            if(prime[i]==i)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    if(prime[j]==j) prime[j] = i;
                }
            }
        }
        
        vector<int> ans;
        
        while(n!=1)
        {
            ans.push_back(prime[n]);
            n = n / prime[n];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
