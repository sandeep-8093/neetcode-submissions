class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string &s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int start, vector<string>&path){
        if(s.length()==start){
            ans.push_back(path);
            return;
        }
        for(int end=start; end<s.length();end++){
            if(isPalindrome(s,start,end)){
                path.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        backtrack(s,0,path);
        return ans;
    }
};
