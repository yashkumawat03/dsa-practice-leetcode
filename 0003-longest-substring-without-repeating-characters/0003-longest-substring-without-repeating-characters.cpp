class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        // Sliding window with freq array(repeating characters check)
        int i = 0, j = 0;
        int max_len = 0;
        vector<bool> freq(256,false);
        while(j<n){
            while(freq[s[j]] == true)  // already in the window
            {
                freq[s[i]] = false;
                i++;
            }

            //not in window
            freq[s[j]] = true;
            int curr_len = j-i+1;
            if(curr_len > max_len){
                max_len = curr_len;
            }
            j++;
        }
        return max_len;
    }
};