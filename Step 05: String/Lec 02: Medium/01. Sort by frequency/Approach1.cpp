class Solution {
public:
    string frequencySort(string s) {
        vector<int> check(128, 0);
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            check[s[i]]++;
        }

        priority_queue<pair<int, char>> qe;
        for (int i = 0; i < 128; ++i) {
            if (check[i] != 0) {
                qe.push({check[i], (char)i});
            }
        }

        string ans = "";
        while (!qe.empty()) {
            auto it = qe.top();
            qe.pop();

            int cnt = it.first;
            char ch = it.second;

            while (cnt > 0) {
                ans.push_back(ch);
                cnt--;
            }
        }
        return ans;
    }
};
