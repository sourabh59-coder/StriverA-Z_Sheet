class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long ans = 0;
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        bool sign = true;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = false;
            }
            i++;
        }
        
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int val = s[i] - '0';
            ans = ans * 10 + val;
            
            if (sign && ans > INT_MAX) return INT_MAX;
            if (!sign && -ans < INT_MIN) return INT_MIN;
            
            i++;
        }
        
        if (!sign) ans = -ans;

        
        
        return static_cast<int>(ans);
    }
};
