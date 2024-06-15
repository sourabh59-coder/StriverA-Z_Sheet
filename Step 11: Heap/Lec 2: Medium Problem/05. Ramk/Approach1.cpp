//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n){
        // vector<int> ans;
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
        
        for(int i=0;i<n;i++)
        {
            qe.push({arr[i],i});
        }
        
        int ind = 0;
        int prev = -1;
        
        while(!qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            
            int val = it.first;
            int i = it.second;
            
            if(prev!=val)
            {
                ind++;
            }
            arr[i] = ind;
            prev = val;
        }
        
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
