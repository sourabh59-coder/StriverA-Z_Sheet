//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void fun(vector<int> &v,int ind,int n,int &sum,vector<int> &ans)
    {
        if(ind==n)
        {
            ans.push_back(sum);
            return;
        }
        
        //notTake
        fun(v,ind+1,n,sum,ans);
        
        //Take
        sum += v[ind];
        fun(v,ind+1,n,sum,ans);
        sum -= v[ind];
    }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        int sum = 0;
        fun(arr,0,n,sum,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
