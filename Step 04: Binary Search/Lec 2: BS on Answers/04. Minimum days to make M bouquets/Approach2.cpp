class Solution {
public:
    bool isPossible(vector<int> &v,int n,int m,int k,int limit)
    {
        int cnt = 0;
        int cnt_total = 0;

        for(int i=0;i<n;i++)
        {
            if(v[i]<=limit)
            {
                cnt++;
            }
            else
            {
                cnt_total += (cnt/k);
                cnt = 0;
            }
        }

        cnt_total += (cnt/k);

        return (cnt_total>=m);
    }
    int minDays(vector<int>& v, int m, int k) {
        int maxv = INT_MIN;
        int n = v.size();
        for(int i=0;i<n;i++)    maxv = max(maxv,v[i]);

        int l = 1;
        int r = maxv;

        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(isPossible(v,n,m,k,mid))
            {
                temp = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }

        return temp;

        // for(int i=1;i<=maxv;i++)
        // {
        //     if(isPossible(v,n,m,k,i))
        //     {
        //         return i;
        //     }
        // }

        // return -1;
    }
};
