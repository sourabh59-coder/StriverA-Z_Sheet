//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int parent(int i)
    {
        return (i-1)/2;
    }
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        bool a = true;
        bool b = true;
        for(int i=1;i<n;i++)
        {
            int par_ind = parent(i);
            if(arr[par_ind] < arr[i])   a = false;
            else if(arr[par_ind] > arr[i])  b = false;
        }
        return (a||b);
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
