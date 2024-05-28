class MinStack {
public:
    stack<int> st;
    int min;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min = val;
        }
        else
        {
            if(val < min)
            {
                st.push((2*val - min));
                min = val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() >= min)  st.pop();
        else
        {
            int val = 2*min - st.top();
            st.pop();
            min = val;
        }
    }
    
    int top() {
        if(st.top()<min)    return min;
        else                return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
