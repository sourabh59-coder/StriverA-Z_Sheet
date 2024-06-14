class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(),v.end(),comp);
        int start = v[0][0];
        int cnt = 0;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            cout<<v[i][0]<<" "<<v[i][1]<<endl;
            if(v[i][0] >= start)
            {
                cnt++;
                start = v[i][1];
            }
        }
        return v.size()-cnt;
    }
};
