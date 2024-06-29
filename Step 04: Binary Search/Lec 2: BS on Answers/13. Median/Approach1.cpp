class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();

        if(n>m) return findMedianSortedArrays(v2,v1);
        bool flag = ((n+m)%2==0);
        int k = (n+m+1)/2;

        int low = 0, high = min(n,k);

        while(low<=high)
        {
            int mid1 = (low+high)/2;
            int mid2 =  k - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if(mid1-1>=0)   l1 = v1[mid1-1];
            if(mid2-1>=0)   l2 = v2[mid2-1];
            if(mid1<n)      r1 = v1[mid1];
            if(mid2<m)      r2 = v2[mid2];

            if(l1<=r2 && l2<=r1)
            {
                double ans;
                if(flag)    ans = (double)(max(l1,l2) + min(r1,r2)) / (double)2;
                else        ans = (double)(max(l1,l2));
                return ans;
            }
            else if(l1>r2)  high = mid1-1;
            else            low = mid1+1;
        }

        return -1;
    }
};
