//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends

int ceil_val(int arr[],int l,int r,int k)
{
    int temp = -1;
    while(l<=r)
    {
        int mid = (r-l)/2 + l;
        if(arr[mid]==k) return arr[mid];
        else if(arr[mid] > k)
        {
            temp = arr[mid];
            r = mid-1;
        }
        else    l = mid+1;
    }
    return temp;
}
int floor_val(int arr[],int l,int r,int k)
{
    int temp = -1;
    
    while(l<=r)
    {
        int mid = (r-l)/2 + l;
        if(arr[mid]==k) return arr[mid];
        else if(arr[mid] < k)
        {
            temp = arr[mid];
            l = mid+1;
        }
        else    r = mid-1;
    }
    
    return temp;
}
pair<int, int> getFloorAndCeil(int arr[], int n, int k ) {
    // code here
    int l = 0, r = n-1;
    sort(arr,arr+n);
    int a = floor_val(arr,l,r,k);
    int b = ceil_val(arr,l,r,k);
    
    return {a,b};
}
