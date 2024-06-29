class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& v) {
        int n = v.size();
        int maxv = INT_MIN, maxi = -1;
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++)
        {
            if(maxv<v[i])
            {
                maxv = v[i];
                maxi = i;
            }
        }
        cout<<maxi<<endl;
        int k = maxi;
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            int ind = k;
            if(ind<0)   ind += n;

            // cout<<v[ind]<<endl;

            while(!st.empty() && st.top() <= v[ind])  st.pop();

            if(st.empty())  ans[ind] = -1;
            else            ans[ind] = st.top();


            st.push(v[ind]);
            k--;
        }

        return ans;
    }
};
