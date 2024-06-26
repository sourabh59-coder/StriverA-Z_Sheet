class Solution {
public:
    bool isPossible(vector<int> &v,int n,int days,int limit)
    {
        int cnt = 1;
        int cap = v[0];
        for(int i=1;i<n;i++)
        {
            if(cap+v[i]>limit)
            {
                cnt++;
                cap = v[i];
            }
            else
            {
                cap += v[i];
            }
        }

        return (cnt<=days);
    }
    int shipWithinDays(vector<int>& v, int days) {
        int n = v.size();
        int l = INT_MIN;
        int r = 0;

        for(int i=0;i<n;i++)
        {
            l = max(l,v[i]);
            r += v[i];
        }

        for(int i=l;i<=r;i++)
        {
            if(isPossible(v,n,days,i))
            {
                return i;
            }
        }

        return -1;
    }
};
