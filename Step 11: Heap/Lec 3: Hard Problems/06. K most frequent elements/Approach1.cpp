class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            mp[v[i]]++ ;
        }
        priority_queue <pair<int,int>> qe;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            qe.push({it->second,it->first});
            // if(qe.size() > k)   qe.pop();
        }
        // return qe.top().second;
        vector<int> ans;
        while(!qe.empty() && k>0)
        {
            ans.push_back(qe.top().second);
            qe.pop();
            k--;
        }
        return ans;
    }
};
