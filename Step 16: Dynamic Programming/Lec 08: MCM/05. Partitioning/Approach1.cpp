#include <bits/stdc++.h>
const int mod = 1000000007;

vector<vector<vector<long long>>> dp;

long long int fun(string &s, int i, int j, int isTrue) {
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;

    for (int k = i + 1; k <= j - 1; k += 2) {
        long long lt = fun(s, i, k - 1, 1);
        long long lf = fun(s, i, k - 1, 0);
        long long rt = fun(s, k + 1, j, 1);
        long long rf = fun(s, k + 1, j, 0);

        if (s[k] == '&') {
            if (isTrue) ways = (ways + (lt * rt) % mod) % mod;
            else ways = (ways + (lt * rf) % mod + (lf * rt) % mod + (lf * rf) % mod) % mod;
        } else if (s[k] == '|') {
            if (isTrue) ways = (ways + (lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else ways = (ways + (lf * rf) % mod) % mod;
        } else if (s[k] == '^') {
            if (isTrue) ways = (ways + (lt * rf) % mod + (lf * rt) % mod) % mod;
            else ways = (ways + (lt * rt) % mod + (lf * rf) % mod) % mod;
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &s) {
    int n = s.length();
    dp = vector<vector<vector<long long>>>(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return fun(s, 0, n - 1, 1);
}
