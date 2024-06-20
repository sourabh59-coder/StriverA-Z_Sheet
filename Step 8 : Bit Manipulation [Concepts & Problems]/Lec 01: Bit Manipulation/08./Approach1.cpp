class Solution {
public:
    int divide(int divident, int divisor) {
        if(divident==divisor)   return 1;
        bool sign = true;
        if(divident<0 && divisor>0) sign = false;
        if(divident>0 && divisor<0) sign = false;

        long long dd = abs(divident);
        long long ds = abs(divisor);

        long long quotent = 0;
        

        while(dd>=ds)
        {
            int cnt = 0;

            while(dd >= (ds<<(cnt+1)))
            {
                cnt++;
            }

            quotent += (1<<cnt);
            dd -= (ds<<cnt);
        }

        if(quotent == (1<<31) && sign)  return INT_MAX;

        if(quotent == (1<<31) && !sign) return INT_MIN;

        return sign ? quotent : (-1*quotent);
    }
};
