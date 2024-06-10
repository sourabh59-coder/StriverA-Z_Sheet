class Solution {
public:
    int searchInsert(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = n-1;
        int temp = n;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(v[mid]==k)   return mid;
            else if(v[mid] > k)
            {
                temp = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }

        return temp;
    }
};
