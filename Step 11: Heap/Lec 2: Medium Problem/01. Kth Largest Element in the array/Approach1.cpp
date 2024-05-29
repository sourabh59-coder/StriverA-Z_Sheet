class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue <int, vector<int>, greater<int>> qe;
        int n = v.size();

        for(int i=0;i<n;i++)
        {
            qe.push(v[i]);
            if(qe.size() > k)
            {
                qe.pop();
            }
        }

        return qe.top();
    }
};
