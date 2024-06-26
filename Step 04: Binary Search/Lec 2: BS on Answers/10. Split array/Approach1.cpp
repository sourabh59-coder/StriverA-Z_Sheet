class Solution {
public:
    int isPossible(vector<int> &v,int n,int k,int thres)
    {
        int cnt = 1;
        int val = v[0];

        for(int i=1;i<n;i++)
        {
            if(v[i]+val>thres)
            {
                cnt++;
                val = v[i];
            }
            else    val += v[i];
        }

        return (cnt<=k);
    }
    int splitArray(vector<int>& v, int k) {
        int n = v.size();
        int l = INT_MAX;
        int r = 0;

        for(int i=0;i<n;i++)
        {
            l = min(v[i],l);
            r += v[i];
        }

        for(int i=l;i<=r;i++)
        {
            if(isPossible(v,n,k,i))
            {
                return i;
            }
        }

        return -1;
    }
};
