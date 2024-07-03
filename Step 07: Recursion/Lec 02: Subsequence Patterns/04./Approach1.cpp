//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctSubsequences(string s)
    {
        int n = s.length();
        vector<int> check(26,-1);
        vector<int> v(n+1,1);
        for(int i=0;i<n;i++)
        {
            v[i+1] = 2*v[i];
            int ind = check[s[i]-'a'];
            if(ind!=-1)
            {
                v[i+1] = v[i+1] - v[ind];
            }
            check[s[i]-'a'] =  i;
        }
        return v[n];
    }
    string betterString(string str1, string str2) {
        // code here
        int v1 = countDistinctSubsequences(str1);
        int v2 = countDistinctSubsequences(str2);
        
        // cout<<v1<< " "<<v2<<endl;
        
        return (v1>=v2) ? str1 : str2;  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
