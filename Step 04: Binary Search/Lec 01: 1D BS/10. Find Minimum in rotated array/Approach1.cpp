class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int  l = 0, r = n-1;
        int temp = arr[0];
        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(arr[l] <= arr[mid])
            {
                temp = min(temp,arr[l]);
                l = mid+1;
            }
            else if(arr[mid]<=arr[r])
            {
                temp = min(temp,arr[mid]);
                r = mid-1;
            }
        }
        return temp;
    }
};
