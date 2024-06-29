class Solution {
public:
    int maxInd(vector<vector<int>> &v,int n,int m,int col)
    {
        int maxi = -1;
        int maxv = -1;

        for(int i=0;i<n;i++)
        {
            if(v[i][col]>maxv)
            {
                maxi = i;
                maxv = v[i][col];
            }
        }

        return maxi;
    }
    vector<int> findPeakGrid(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        int low  = 0, high = m-1;
        while(low<=high)
        {
            int mid = (high+low)/2;

            int max_ind = maxInd(v,n,m,mid);

            int left = (mid-1>=0) ? v[max_ind][mid-1]:-1;
            int right = (mid+1<m) ? v[max_ind][mid+1]:-1;
            int val = v[max_ind][mid];

            if(val>left && val>right)   return {max_ind,mid};
            else if(left<val && val<right)  low = mid+1;
            else                            high = mid-1;
        }

        return {-1,-1};
    }
};
