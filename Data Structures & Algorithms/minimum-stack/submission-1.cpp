class MinStack {
public:
    stack<int>st;
    stack<int>minst;
    MinStack() {
        
    }
    
    void push(int val) {
        // top++;
        st.push(val);
        if(minst.empty() || val <= minst.top()){
            minst.push(val);
        }
    }
    
    void pop() {
        // if(top>=0){
        //     top--;
        // }
        if(st.empty())
            return;
        int val1 = st.top();
        st.pop();
        if(!minst.empty() && minst.top()==val1){
            minst.pop();
        }
    }
    
    int top() {
        // return arr[top];
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        return -1;
    }
};
