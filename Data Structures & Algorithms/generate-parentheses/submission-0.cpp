class Solution {
public:
    vector<string>ans;
    void backtrack(int start, int end, int n, string s){
        if(s.length() == 2*n){
            ans.push_back(s);
            return;
        }
        if(start<n){
            backtrack(start+1, end, n, s+'(');
        }
        if(end<start){
            backtrack(start, end+1, n, s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(0,0,n,"");
        return ans;
    }
};
