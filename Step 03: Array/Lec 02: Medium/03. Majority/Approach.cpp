class Solution {
public:
    int majorityElement(vector<int>& v) {
        int n = v.size();
        int cnt = 1;
        int ele = v[0];

        for(int i=1;i<n;i++)
        {
            if(cnt==0)
            {
                ele = v[i];
                cnt++;
            }
            else
            {
                if(ele==v[i])   cnt++;
                else            cnt--;
            }
        }

        return ele;
    }
};
