class StockSpanner {
public:
    int idx = 0;
    stack<pair<int, int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        idx++;
        // Not empty 
        // check if we have less
        while(!st.empty() && st.top().first<=price)
            st.pop();
        // Now we have only greater elements  
        int val = idx;
        if(!st.empty())
            val = idx - st.top().second;
        st.push({price, idx});
        return val;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */