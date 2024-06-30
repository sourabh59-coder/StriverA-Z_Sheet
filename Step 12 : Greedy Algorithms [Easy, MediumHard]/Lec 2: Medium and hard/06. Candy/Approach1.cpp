class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();
        vector<int> check(n,1);
        int ans = 0;
        for(int i=1;i<n;i++)
        {
            if(v[i]>v[i-1]) check[i] = check[i-1]+1;
        }

        for(int i=n-1;i>0;i--)  if(v[i-1]>v[i] && check[i-1]<=check[i]) check[i-1] = check[i]+1;

        for(int i=0;i<n;i++)    ans += check[i];

        return ans;
    }
};
