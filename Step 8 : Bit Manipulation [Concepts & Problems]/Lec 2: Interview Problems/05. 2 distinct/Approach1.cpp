//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int v[], long long int n)  
    {
        // code here
        long long int xorall = v[0];
        for(int i = 1; i < n; i++)    
            xorall ^= v[i];
    
        long long int val = (xorall & (xorall - 1)) ^ xorall;
    
        long long int b1 = 0, b2 = 0;
    
        for(int i = 0; i < n; i++)
        {
            if(val & v[i])  
                b1 ^= v[i];
            else            
                b2 ^= v[i];
        }
    
        if (b1 > b2)
            return {b1, b2};
        else
            return {b2, b1};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
