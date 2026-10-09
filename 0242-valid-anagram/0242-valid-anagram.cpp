class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq1(25);
        vector<int> freq2(25);
        for(int i = 0; i < s.length(); i++){
            freq1[s[i] - 'a']++;
            freq2[t[i] - 'a']++;
        }
        if(freq1 == freq2) return true;
        return false;

    }
};