#include <bits/stdc++.h>

vector<int> Solution::solve(vector<int> &v1, vector<int> &v2, int k) {
    priority_queue<pair<int,pair<int,int>>> qe;
    int n = v1.size();
    int m = v2.size();
    sort(v1.begin(),v1.end(),greater<int>());
    sort(v2.begin(),v2.end(),greater<int>());
    set<pair<int,int>> st;
    
    int val = v1[0]+v2[0];
    st.insert({0,0});
    
    qe.push({val,{0,0}});
    vector<int> ans;
    while(!qe.empty() && k>0)
    {
        auto it = qe.top();
        qe.pop();
        
        int val = it.first;
        int i = it.second.first;
        int j = it.second.second;
        
        ans.push_back(val);
        k--;
        int val1 =0 ,val2 = 0;
        if(i+1<n && st.count({i+1,j})==0)
        {
            val1 = v1[i+1] + v2[j];
            st.insert({i+1,j});
        } 
        if(j+1<m && st.count({i,j+1})==0)
        {
            val2 = v1[i] + v2[j+1];
            st.insert({i,j+1});
        } 
        
        qe.push({val1,{i+1,j}});
        qe.push({val2,{i,j+1}});
    }
    
    return ans;
}
