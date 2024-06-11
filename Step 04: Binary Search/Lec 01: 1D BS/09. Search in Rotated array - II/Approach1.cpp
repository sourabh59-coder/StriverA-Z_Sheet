class Solution {
public:
    bool search(vector<int>& v, int k) {
        int n = v.size();
        int l = 0, r = n-1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(v[mid]==k)   return true;

            if(v[l]==v[mid] && v[mid]==v[r])
            {
                l++;
                r--;
                continue;
            }
            else if(v[l]<=v[mid])
            {
                if(v[l] <= k && k <= v[mid])  r = mid-1;
                else            l = mid+1;
            }
            else
            {
                if(v[mid] <=k && k <= v[r])  l = mid+1;
                else            r = mid-1;
            }
        }

        return false;
    }
};
