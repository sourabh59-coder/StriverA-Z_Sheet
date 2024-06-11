//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int first_occurence(vector<int> v,int l,int r,int k)
    {
        int temp = -1;
        
        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(v[mid]==k)
            {
                temp = mid;
                r = mid - 1;
            }
            else if(v[mid] < k) l = mid + 1;
            else                r = mid - 1;
        }
        
        return temp;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int a = -1, b = m;
	    for(int i=0;i<n;i++)
	    {
	        int l = 0, r = m-1;
	        int ind = first_occurence(arr[i],l,r,1);
	        if(ind!=-1)
	        {
	            if(ind < b)
	            {
	                a = i;
	                b = ind;
	            }
	        }
	    }
	    
	    return a;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
