class Solution {
public:
    int fun(vector<int> &v,int ind,int n,int buy,int k)
    {
        if(ind==n)  return 0;

        if(k>0)
        {
            if(buy==1)
            {
                return max((0+fun(v,ind+1,n,buy,k)),(-v[ind]+fun(v,ind+1,n,1-buy,k)));
            }

            else
            {
                return max((0+fun(v,ind+1,n,buy,k)),(v[ind]+fun(v,ind+1,n,1-buy,k-1)));
            }
        }

        return 0;
    }
    int maxProfit(vector<int>& v) {
        int n = v.size();
        int k = 2;
        return fun(v,0,n,1,k);
    }
};
