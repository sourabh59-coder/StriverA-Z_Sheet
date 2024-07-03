//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<pair<char,pair<int,int>>> moments = {{'L',{0,-1}},{'U',{-1,0}},{'R',{0,1}},{'D',{1,0}}};
    void fun(vector<vector<int>> &v,int i,int j,int n,vector<string> &ans,string &s,vector<vector<int>> &vis)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(s);
            return;
        }
        
        for(auto moment: moments)
        {
            char dir = moment.first;
            int x = i + moment.second.first;
            int y = j + moment.second.second;
            
            if(x>=0 && y>=0 && x<n  && y<n && v[x][y]==1 && !vis[x][y])
            {
                s.push_back(dir);
                vis[x][y] = 1;
                fun(v,x,y,n,ans,s,vis);
                s.pop_back();
                vis[x][y] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> ans;
        string s;
        
        vector<vector<int>> vis(n,vector<int> (n,0));
        
        if(v[0][0]==0)  return ans;
        
        vis[0][0] = 1;
        fun(v,0,0,n,ans,s,vis);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
