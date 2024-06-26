class Solution {
public:
    bool isPossible(vector<int> &v,int n,int thres,int val)
    {
        int cal = 0;
        for(int i=0;i<n;i++)
        {
            cal += ceil((double)v[i]/(double)val);
        }
        return (cal<=thres);
    }
    int smallestDivisor(vector<int>& v, int thres) {
        int n = v.size();
        int maxv = INT_MIN;
        for(int i=0;i<n;i++)    maxv = max(maxv,v[i]);

        int l = 1;
        int r = maxv;
        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(isPossible(v,n,thres,mid))
            {
                temp = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }

        return temp;
        // for(int i=1;i<=maxv;i++)
        // {
        //     if(isPossible(v,n,thres,i))
        //     {
        //         return i;
        //     }
        // }
        // return -1;
    }
};
