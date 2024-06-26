class Solution {
public:
    int jump(vector<int>& v) {
        int n = v.size();
        int l = 0, r = 0;
        int jump = 0;
        while(r < n-1)
        {
            int farthest = 0;
            for(int i=l;i<=r;i++)
            {
                farthest = max(farthest,i + v[i]);
            }
            l = r+1;
            r = farthest;
            jump++;
        }
        return jump;
    }
};
