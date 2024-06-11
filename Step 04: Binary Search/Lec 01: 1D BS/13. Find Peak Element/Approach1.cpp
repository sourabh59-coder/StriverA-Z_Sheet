class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size();
        int l = 1, r = n-2;

        if(n==1)    return 0;

        if(arr[0]>arr[1])   return 0;

        if(arr[n-2]<arr[n-1])   return n-1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])  return mid;

            else if(arr[mid-1] < arr[mid]) l = mid+1;

            else if(arr[mid] > arr[mid+1]) r = mid-1;

            else                        r = mid-1;
        }

        return -1;
    }
};
