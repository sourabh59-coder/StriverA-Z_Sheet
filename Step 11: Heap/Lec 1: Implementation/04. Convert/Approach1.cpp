//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Heapify(vector<int> &arr,int i,int n)
    {
        int left = (2*i+1);
        int right = (2*i+2);
        int parent = i;
        
        if(left<n && arr[left]>arr[parent])
        {
            parent = left;
        }
        
        if(right<n && arr[right]>arr[parent])
        {
            parent = right;
        }
        
        if(parent!=i)
        {
            swap(arr[parent],arr[i]);
            Heapify(arr,parent,n);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i=N-1/2;i>=0;i--)
        {
            Heapify(arr,i,N);
        }
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
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
