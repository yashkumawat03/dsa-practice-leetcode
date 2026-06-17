class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<int> freq(256);
        for(char ch : t){
            freq[ch]++;
        }
        int left = 0;
        int right = 0;
        int cnt = 0;
        int len = INT_MAX;
        int start = -1;
        
        while(right < n){
            if(freq[s[right]] > 0){
                cnt++;
            }
            freq[s[right]]--;

            while(cnt == m){
                if(right - left + 1 < len){
                    start = left;
                    len = right - left + 1;
                }
                freq[s[left]]++;
                if(freq[s[left]] > 0)
                    cnt--;
                left++;
            }
            right++;
        }
        if(len == INT_MAX) return "";
        return s.substr(start, len);
    }
};