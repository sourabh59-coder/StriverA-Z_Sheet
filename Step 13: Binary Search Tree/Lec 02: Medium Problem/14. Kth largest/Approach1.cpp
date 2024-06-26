//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int a[], int b[], int n, int m, int k)
    {
        if(n>m) return kthElement(b,a,m,n,k);
        
        int l = max(k-m,0);
        int r = min(k,n);
        
        int left = k;
        int tot = n+m;
        
        while(l<=r)
        {
            int mid1 = (r+l)/2;
            
            int mid2 = left - mid1;
            
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            
            if(mid1<n)  r1 = a[mid1];
            if(mid2<m)  r2 = b[mid2];
            
            if(mid1-1>=0)   l1 = a[mid1-1];
            if(mid2-1>=0)   l2 = b[mid2-1];
            
            if(l1<=r2 && l2<=r1)    return max(l1,l2);
            else if(l1>l2)  r = mid1-1;
            else            l = mid1+1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
