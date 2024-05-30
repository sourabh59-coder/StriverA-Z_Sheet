int findFloor(vector<long long> arr, long long n, long long x){
        
        // Your code here
        long long r = n-1, l = 0;
        int temp = -1;
        
        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(arr[mid]==x)
            {
                temp = mid;
                return temp;
            }
            else if(arr[mid] < x)
            {
                temp = mid;
                l = mid+1;
            }
            else    r = mid-1;
        }
        
        return temp;
    }
