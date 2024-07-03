class Solution {
public:
    bool fun(string &s,int ind,int n,unordered_set<string> &st)
    {
        if(ind==n)
        {
            return true;
        }
        bool ans = false;
        for(int i=ind;i<n;i++)
        {
            string check = s.substr(ind,i-ind+1);
            if(st.count(check))
            {
                ans  |= fun(s,i+1,n,st);
            }
        }

        return ans;
    }
    bool wordBreak(string s, vector<string>& vec) {
        unordered_set<string> st;
        for(int i=0;i<vec.size();i++)
        {
            st.insert(vec[i]);
        }
        int n = s.length();
        // bool ans = false;
        return fun(s,0,n,st);
    }
};
