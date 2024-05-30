class Solution {
public:
    int search(vector<int>& v, int k) {
        int l = 0, r = v.size()-1;

        while(l<=r)
        {
            int mid = l + (r-l)/2;

            if(v[mid] == k)
            {
                return mid;
            }
            else if(v[mid] < k)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }

        return -1;
    }
};
