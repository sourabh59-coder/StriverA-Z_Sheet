class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int n = v.size();
        int sum = 0;
        
        for (int i = 0; i < k; ++i) {
            sum += v[i];
        }

        int ans = sum;
        
        for (int i = 0; i < k; ++i) {
            sum -= v[k - 1 - i];  
            sum += v[n - 1 - i];  
            ans = max(ans, sum);
        }

        return ans;
    }
};
