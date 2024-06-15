class Solution {
public:
    bool check(vector<int> &v,int mid,int h)
    {
        long long sum = 0;
        for(int i=0;i<v.size();i++)
        {
            sum += v[i]/mid;
            if(v[i]%mid>0) sum++;
        }
        return (sum<=h);
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int n = v.size();
        sort(v.begin(),v.end());
        int l = 1, r = v[n-1];
        int temp = -1;

        while(l<=r)
        {
            int mid = (r-l)/2 + l;

            if(check(v,mid,h))
            {
                temp = mid;
                r = mid-1;
            }
            else    l = mid+1;
        }

        return temp;
    }
};
