class Solution {
public:
    void pow(long long &x,long long &n,long long &ans)
    {
        int mod = 1e9+7;
        if(n==0)    return;
        if(n%2==0)
        {
            x = (x*x)%mod;
            n = n/2;
            pow(x,n,ans);
        }
        else
        {
            ans = (ans*x)%mod;
            n = n-1;
            pow(x,n,ans);
        }
    }
    int countGoodNumbers(long long n) {
        long long res = 1;
        long long cnt5 = (n+1)/2;
        long long cnt4 = (n)/2;
        int mod = 1e9+7;
        long long ans = 1;
        long long val5 = 5;
        long long val4 = 4;
        pow(val5,cnt5,ans);
        res = (res*ans)%mod;
        ans = 1;
        pow(val4,cnt4,ans);
        res = (res*ans)%mod;
        return res;
    }
};
