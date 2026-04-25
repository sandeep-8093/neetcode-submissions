class Solution {
public:
    int characterReplacement(string s, int k) {
        int max_count=0;int left=0; int max_len=0;
        vector<int>freq(26,0);
        for (int i=0;i<s.length(); i++){
            freq[s[i] - 'A']++;
            max_count = max(max_count, freq[s[i] - 'A']);

            while((i-left+1) - max_count > k){
                freq[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len, i-left+1);
        }
        return max_len;
    }
};
