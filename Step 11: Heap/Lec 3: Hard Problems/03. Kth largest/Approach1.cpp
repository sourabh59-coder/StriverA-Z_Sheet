class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> qe;
    int K ;
    KthLargest(int k, vector<int>& v) {
        int n = v.size();
        K = k;
        for(int i=0;i<n;i++)
        {
            qe.push(v[i]);
        }
        while(qe.size()>k)
        {
            qe.pop();
        }
    }
    
    int add(int val) {
        qe.push(val);
        if(qe.size() > K)   qe.pop();
        return qe.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
