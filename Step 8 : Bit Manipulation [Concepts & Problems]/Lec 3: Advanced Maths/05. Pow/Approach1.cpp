class Solution {
public:
    double myPow(double x, int n1) {
        ios_base::sync_with_stdio(0);
        long long n = n1;
        bool flag = false;
        if(n<0)
        {
            flag = true;
            n = (-1) * n;
        } 

        double ans = 1.0;
        while(n)
        {
            if(n%2==1)
            {
                ans *= x;
                n--;
            }
            else
            {
                x *= x;
                n /= 2;
            }
        }
        if(flag)
        {
            ans = (double)1/ans;
        }

        return ans;
    }
};
