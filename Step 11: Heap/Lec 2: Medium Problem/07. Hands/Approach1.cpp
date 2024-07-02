class Solution {
public:
    bool isNStraightHand(vector<int>& v, int k) {
        int ans = 0;
        queue<pair<int,int>> qe;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pr_qe;
        int n = v.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[v[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pr_qe.push({it->first,it->second});
        }
        int len = 0;
        int prev = -1;
        while(!pr_qe.empty())
        {
            auto it = pr_qe.top();
            pr_qe.pop();

            int val = it.first;
            int cnt = it.second;
            if(cnt>1)
            {
                qe.push({val,cnt-1});
            }

            if(prev==-1 || val-1==prev)
            {
                len++;
                prev = val;
            }
            else
            {
                if(len!=0)  return false;
                while(!qe.empty())  qe.pop();
                prev = -1;
                len = 0;
            }

            if(len == k)
            {
                ans++;
                prev = -1;
                len = 0;
                while(!qe.empty())
                {
                    pr_qe.push(qe.front());
                    qe.pop();
                }
            }
            if(len>k)   return false;

            // if(ans==k)  return true;
        }

        if(len!=0)  return false;

        // if()

        return true;
    }
};
