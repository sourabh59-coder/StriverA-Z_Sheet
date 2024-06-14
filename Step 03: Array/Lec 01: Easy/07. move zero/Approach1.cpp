class Solution {
public:
    void moveZeroes(vector<int>& v) {
        int n = v.size();
        if(n==0 || n==1)    return;
        int l = 0, r = 0;
        while(l<n && r<n)
        {
            if(l==r)
            {
                if(v[l]==0)
                {
                    r++;
                }
                else
                {
                    l++;
                    r++;
                }
            }
            else
            {
                if(v[l]==0 && v[r]!=0)
                {
                    swap(v[l],v[r]);
                    l++;
                }
                else if(v[l]!=0)
                {
                    l++;
                }
                else if(v[l]==0 && v[r]==0)
                {
                    r++;
                }
            }
        }
    }
};
