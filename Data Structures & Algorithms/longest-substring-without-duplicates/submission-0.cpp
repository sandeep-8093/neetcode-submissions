class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;

        int longest=0;
        unordered_set<char>seen;
        for(int i=0;i<s.length(); i++){
            while(seen.find(s[i])!=seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            longest = max(longest,i-left+1);
        }
        return longest;
    }
};
