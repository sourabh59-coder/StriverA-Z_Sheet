class Solution {
public:
    int fun(vector<int> &v,int i,int j)
    {
        if(i>j) return 0;

        int ans = INT_MAX;

        for(int k=i;k<=j;k++)
        {
            int val = v[j+1]-v[i-1] + fun(v,i,k-1) + fun(v,k+1,j);

            ans = min(val,ans);
        }

        return ans;
    }
    int minCost(int n, vector<int>& v) {
        v.push_back(0);
        v.push_back(n);
        sort(v.begin(),v.end());
        n = v.size();
        return fun(v,1,n-2);
    }
};
