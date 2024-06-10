class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int l = 0, r = n-1;

        while(l<=r)
        {
            int mid  = (r-l)/2 + l;

            if(mid%2==0)
            {
                int ind_r = mid+1;
                int ind_l = mid-1;
                if(ind_r<n)
                {
                    if(arr[ind_r] == arr[mid])  l = mid+1;
                    else if(ind_l>=0)
                    {
                        if(arr[ind_l]==arr[mid])    r = mid-1;
                        else    return arr[mid];
                    }
                    else    return arr[mid];
                }
                else        return arr[mid];
            }
            else
            {
                int ind_r = mid+1;
                int ind_l = mid-1;
                if(ind_l>=0)
                {
                    if(arr[ind_l]==arr[mid])    l = mid+1;
                    else if(ind_r < n)
                    {
                        if(arr[ind_r]==arr[mid])    r = mid-1;
                        else                        return arr[mid];
                    }
                    else                            return arr[mid];
                }
                else        return arr[mid];
            }
        }

        return -1;
    }
};
