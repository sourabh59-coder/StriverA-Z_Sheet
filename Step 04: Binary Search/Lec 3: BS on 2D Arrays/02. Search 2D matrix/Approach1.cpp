class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();
        int l = 0, r = n-1;
        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;
            if(v[mid][0]==k)   return true;
            else if(v[mid][0] < k)
            {
                temp = mid;
                l = mid+1;
            }
            else    r = mid-1;
        }

        if(temp==-1)    return false;
        else
        {
            l = 0, r = m-1;
            while(l<=r)
            {
                int mid = (r-l)/2 + l;

                if(v[temp][mid]==k) return true;
                else if(v[temp][mid] < k)   l = mid+1;
                else                        r = mid-1;
            }
            return false;
        }
    }
};
