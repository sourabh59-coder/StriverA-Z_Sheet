class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> check(3,-1);
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            check[s[i]-'a'] = i;
            ans += 1 + min(check[0],min(check[1],check[2]));
        }
        return ans;
    }
};
