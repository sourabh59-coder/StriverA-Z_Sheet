class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size();
        int cnt1 = 0, cnt2 = 0;
        int ele1 = 0, ele2 = 0;

        for(int i=0; i<n; i++) {
            if(cnt1 == 0 && v[i] != ele2) {
                ele1 = v[i];
                cnt1++;
            } else if(cnt2 == 0 && v[i] != ele1) {
                ele2 = v[i];
                cnt2++;
            } else if(ele1 == v[i]) {
                cnt1++;
            } else if(ele2 == v[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<n; i++) {
            if(ele1 == v[i]) cnt1++;
            if(ele2 == v[i]) cnt2++;
        }

        int val = (int)(n / 3) + 1;
        vector<int> ans;
        if(cnt1 >= val) ans.push_back(ele1);
        if(cnt2 >= val) ans.push_back(ele2);

        sort(ans.begin(), ans.end());
        return ans;
    }
};
