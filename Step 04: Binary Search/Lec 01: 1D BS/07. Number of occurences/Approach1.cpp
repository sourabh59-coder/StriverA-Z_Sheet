//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int first(int arr[],int l,int r,int k)
	{
	    int temp = -1;
	    
	    while(l<=r)
	    {
	        int mid =  (r-l)/2 + l;
	        
	        if(arr[mid]==k)
	        {
	            temp = mid;
	            r = mid-1;
	        }
	        else if(arr[mid] < k)   l = mid+1;
	        else                    r = mid-1;
	    }
	    
	    return temp;
	}
	int last(int arr[],int l,int r,int k)
	{
	    int temp = -1;
	    
	    while(l<=r)
	    {
	        int mid  = (r-l)/2 + l;
	        
	        if(arr[mid]==k)
	        {
	            temp = mid;
	            l = mid+1;
	        }
	        else if(arr[mid]<k) l = mid+1;
	        else                r = mid-1;
	    }
	    
	    return temp;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int l = 0, r = n-1;
	    
	    int a = first(arr,l,r,x);
	    int b = last(arr,l,r,x);
	    
	    if(a!=-1 && b!=-1)  return (b-a+1);
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
