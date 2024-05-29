int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> qe;
        for(int i=l;i<=r;i++)
        {
            qe.push(arr[i]);
            if(qe.size() > k)   qe.pop();
        }
        return qe.top();
    }
