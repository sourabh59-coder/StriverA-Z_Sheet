class Solution {
public:
    int strStr(string s, string t) {
        int N = 1e5+7;
        int mod = (int)(1e9+7);
        int n = s.length();
        int m = t.length();

        vector<long long> power(N,0);
        int p = 31;
        power[0] = 1;
        for(int i=1;i<N;i++)
        {
            power[i] = (power[i-1]*p)%mod;
        }

        long long int hash_t = 0;
        for(int i=0;i<m;i++)
        {
            long long val = t[i]-'a';
            hash_t = (hash_t + (val*power[i])%mod)%mod;
        }

        vector<long long int> hash_s(n+1,0);
        for(int i=0;i<n;i++)
        {
            long long val = s[i]-'a';
            long long int che = (val*power[i])%mod;
            hash_s[i+1] = (hash_s[i] + che) % mod;
        }

        for(int i=0;i<n-m+1;i++)
        {
            long long curr_hash = (hash_s[i+m] - hash_s[i] + mod)%mod;
            if(curr_hash == (hash_t * power[i])%mod)
            {
                return i;
            }
        }
        return -1;
    }
};
