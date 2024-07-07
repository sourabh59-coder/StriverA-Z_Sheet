class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        int m = v.size();
        unordered_map<char,int> mp;
        queue<pair<int,int>>  qe;
        priority_queue<int> q;

        for(int i=0;i<m;i++)    mp[v[i]]++;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            q.push(it->second);
        }

        int time = 0;
        while(!q.empty() || !qe.empty())
        {
            time++;
            if(!q.empty())
            {
                int cnt = q.top();
                q.pop();
                if(cnt>1)   qe.push({cnt-1,time+n});
            }
            while(!qe.empty())
            {
                if(qe.front().second == time)
                {
                    q.push(qe.front().first);
                    qe.pop();
                }
                else    break;
            }
        }

        return time;
    }
};
