//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int v[],  int n, int k) 
    { 
        long long sum = 0;
        unordered_map<long long,int> mp;
        mp[sum] = 0;
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            sum += v[i];
            long long val = sum-k;
            if(mp.count(val)!=0)
            {
                ans = max(ans,i+1 - mp[val]);
            }
            if(mp.count(sum)==0)
            {
                mp[sum] = i+1;
            }
        }
        return ans;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
