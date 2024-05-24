class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,int fee)
    {
        if(ind==n)  return 0;

        if(buy==1)  return max((0+fun(v,ind+1,n,buy,fee)),(-v[ind]+fun(v,ind+1,n,1-buy,fee)));

        else        return max((0+fun(v,ind+1,n,buy,fee)),(v[ind]+fun(v,ind+1,n,1-buy,fee)-fee));
    }
    int maxProfit(vector<int>& v, int fee) {
        int n = v.size();
        return fun(v,0,n,1,fee);
    }
};
