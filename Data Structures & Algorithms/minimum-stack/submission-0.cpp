class MinStack {
public:
   stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int val) {
         if(minSt.empty()){
            st.push(val);
            minSt.push(val);
            return;
         }
         st.push(val);
         int check= minSt.top();
    minSt.push(min(check,val));
        
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
         return minSt.top();
    }
};
