//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool comp(pair<pair<int,int>,int> &a,pair<pair<int,int>,int> &b)
{
    if (a.first.second == b.first.second)
        return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({{start[i],end[i]},i});
        }
        sort(v.begin(),v.end(),comp);
        int cnt = 0;
        int on = 0;
        for(int i=0;i<n;i++)
        {
            int a = v[i].first.first;
            int b = v[i].first.second;
            int ind = v[i].second;
            // cout<<a<<" "<<b<<" "<<ind<<endl;
            
            if(a > on)
            {
                cnt++;
                on = b;
            }
        }
        return cnt;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends
