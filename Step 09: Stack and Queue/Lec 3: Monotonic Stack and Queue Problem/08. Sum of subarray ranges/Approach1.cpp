class Solution {
public:
    vector<int> NSL(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().second>=v[i])    st.pop();

            if(st.empty())  ans.push_back(-1);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }

        return ans;
    }
    vector<int> NGL(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;

        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().second<=v[i])    st.pop();

            if(st.empty())  ans.push_back(-1);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }

        return ans;
    }
    vector<int> NSR(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().second>v[i])    st.pop();

            if(st.empty())  ans.push_back(n);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
    vector<int> NGR(vector<int> &v,int n)
    {
        vector<int> ans;
        stack<pair<int,int>> st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().second<v[i])    st.pop();

            if(st.empty())  ans.push_back(n);
            else            ans.push_back(st.top().first);

            st.push({i,v[i]});
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
    long long subArrayRanges(vector<int>& v) {
        int n = v.size();
        vector<int> sl = NSL(v,n);
        vector<int> sr = NSR(v,n);
        vector<int> gl = NGL(v,n);
        vector<int> gr = NGR(v,n);


        long long ans = 0;

        for(int i=0;i<n;i++)
        {
            long long si = (i-sl[i])*(sr[i]-i);
            long long gi = (i-gl[i])*(gr[i]-i);

            ans += (gi-si) * v[i];
        }

        return ans;
    }
};
