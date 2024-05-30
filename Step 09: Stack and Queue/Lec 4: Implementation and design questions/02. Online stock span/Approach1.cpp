class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int v) {
        int span = 1;

        while(!st.empty() && st.top().first <= v)
        {
            span += st.top().second;
            st.pop();
        }

        st.push({v,span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
