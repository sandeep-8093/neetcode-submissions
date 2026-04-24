class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0) return true;
        int end = s.length();
        int start=0;

        while(start<end){
            if(!isalnum(s[start])) {
                start++;
                continue;
            }
            if(!isalnum(s[end])) {
                end--; 
                continue; 
            }
            if(tolower(s[start]) != tolower(s[end])) return false;
            else{
                start++;
                end--;
            }
        }
        return true;
    }
};
