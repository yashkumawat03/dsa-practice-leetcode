class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int maxLen = 0;
        vector<int> freq(256);
        while(j < n){
            while(freq[s[j]] == 1){
                freq[s[i]] = 0;
                i++;
            }
            freq[s[j]] = 1;
            maxLen = max(j - i + 1, maxLen);
            j++;
        }
        return maxLen;
    }
};