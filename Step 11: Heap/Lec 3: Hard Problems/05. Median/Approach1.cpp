class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int> > min;
    MedianFinder() {
        // max.clear();
        // min.clear();
    }
    
    void addNum(int num) {
        if(max.empty() || max.top()>=num)
        {
            max.push(num);
        }
        else
        {
            min.push(num);
        }
        
        if(max.size()>min.size()+1)
        {
            int val = max.top();
            min.push(val);
            max.pop();
        }
        else if(max.size() < min.size())
        {
            int val = min.top();
            max.push(val);
            min.pop();
        }
    }
    
    double findMedian() {
        if(min.size()>max.size()){
            return max.top();
        }
        if(max.size()>min.size()){
            return max.top();
        }
        return (max.top()+min.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
