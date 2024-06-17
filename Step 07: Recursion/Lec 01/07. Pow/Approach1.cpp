class Solution {
public:
    void fun(double &x,long long &n,double &ans)
    {
        if(n==0)
        {
            return;
        }

        if(n%2==0)
        {
            x *= x;
            n = n/2;
            fun(x,n,ans);
        }
        else
        {
            ans *= x;
            n = n-1;
            fun(x,n,ans);
        }
    }
    double myPow(double x, int n1) {
        long long n = n1;
        bool flag = false;
        if(n<0)
        {
            flag = true;
            n = (-1)*n;
        }
        double ans = 1;
        fun(x,n,ans);
        if(flag)
        {
            ans = (double)1 / ans;
        }
        return ans;
    }
};
