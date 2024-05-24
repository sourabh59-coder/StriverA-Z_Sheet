class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int sum)
    {
        if(sum==0)  return 1;

        if(ind==n)  return 0;

        int notTake = fun(v,ind+1,n,sum);

        int Take = 0;

        if(v[ind] >= sum)   Take = fun(v,ind+1,n,sum-v[ind]);

        return (notTake | Take);
    }
    bool canPartition(vector<int>& v) {
        int sum(0);
        for(int i=0;i<v.size();i++)     sum += v[i];
        if(sum%2!=0)    return false;

        sum = sum/2;
        int n = v.size();
        return fun(v,0,n,sum);
    }
};
