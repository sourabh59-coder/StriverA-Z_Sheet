class Solution {
public:
    int ERT(vector<int> &v,int l,int r,int k)
    {
        int temp = -1;
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
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();

        int l = 0, r = m-1;

        while(r>=0 && l<n)
        {
            int ind = ERT(v[l],0,r,k);
            if(ind==-1)
            {
                l++;
            }
            else if(v[l][ind]==k)   return true;
            else r--;
        }

        return false;
    }
};
