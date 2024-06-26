class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            if(v[i]<=k) k++;
            else    return k;
        }
        return k;
    }
};
