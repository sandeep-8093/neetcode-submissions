class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& str : tokens) {
            if (str == "+" || str == "-" || str == "*" || str == "/") {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                if (str == "+") st.push(left + right);
                else if (str == "-") st.push(left - right);
                else if (str == "*") st.push(left * right);
                else if (str == "/") st.push(left / right); // truncates toward zero
            } else {
                st.push(stoi(str)); // convert string to int
            }
        }
        return st.top();
    }
};
