class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char str: s){
            if(str =='{' || str == '(' || str=='['){
                st.push(str);
            }
            else{
                if(!st.empty()){
                    if( (str == ')' && st.top()=='(') || (str == '}' && st.top()=='{') || (str == ']' && st.top()=='['))
                    {
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};
