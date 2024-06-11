//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int temp = arr[0];
	    int ind = 0;
	    int l = 0, r = n-1;
	    
	    while(l<=r)
	    {
	        int mid = (r-l)/2 + l;
	        
	        if(arr[l] <= arr[mid])
	        {
	            if(temp > arr[l])
	            {
	                temp = arr[l];
	                ind = l;
	            }
	            
	            l = mid+1;
	        }
	        else if(arr[mid]<=arr[r])
	        {
	            if(temp > arr[mid])
	            {
	                temp = arr[mid];
	                ind = mid;
	            }
	            
	            r = mid-1;
	        }
	    }
	    
	    return ind;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
