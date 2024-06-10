class Solution {
public:
    int first_occurence(vector<int> &arr,int l,int r,int k)
    {
        int temp = -1;
        
        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(arr[mid]==k)
            {
                temp = mid;
                r = mid-1;
            }
            else if(arr[mid] < k)   l = mid+1;
            else                    r = mid-1;
        }

        return temp;
    }
    int last_occurence(vector<int> &arr,int l,int r,int k)
    {
        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(arr[mid]==k)
            {
                temp = mid;
                l =mid+1;
            }

            else if(arr[mid] < k)   l = mid + 1;
            else                    r = mid - 1;
        }

        return temp;
    }
    vector<int> searchRange(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = n-1;
        int a = first_occurence(v,l,r,k);
        int b = last_occurence(v,l,r,k);
        return {a,b};
    }
};
