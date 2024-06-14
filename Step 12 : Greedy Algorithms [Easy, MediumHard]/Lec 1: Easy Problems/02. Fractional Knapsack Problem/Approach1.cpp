//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // Your code here
        priority_queue<pair<double,pair<int,int>>> qe;
        for(int i=0;i<n;i++)
        {
            int val = arr[i].value;
            int wt = arr[i].weight;
            
            double frac = (double)val / (double)wt;
            qe.push({frac,{val,wt}});
        }
        
        double ans = 0;
        
        while(w && !qe.empty())
        {
            auto it = qe.top();
            qe.pop();
            
            int val = it.second.first;
            int wt = it.second.second;
            
            if(w>=wt)
            {
                ans += (double)val;
                w -= wt;
            }
            else
            {
                double temp = (double)it.first * w;
                ans += (double) temp;
                w = 0;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
