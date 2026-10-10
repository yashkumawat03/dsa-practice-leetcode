class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(m > n) return {};
        int i = 0;
        int j = 0;
        vector<int> ans;
        vector<int> freq1(26);
        vector<int> freq2(26);
        for(char ch : p){
            freq2[ch - 'a']++;
        }
        while(j < n){
            while(j - i + 1 <= m){
                freq1[s[j] - 'a']++;
                j++;
            }
            if(freq1 == freq2) ans.push_back(i);
            freq1[s[i] - 'a']--;
            i++;
        }
        return ans;
    }
};