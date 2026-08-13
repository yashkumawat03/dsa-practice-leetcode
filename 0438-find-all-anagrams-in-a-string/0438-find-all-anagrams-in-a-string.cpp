class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> freqp(256);
        if(p.length() > s.length()){
            return ans;
        }
        for(int i = 0; i < p.length(); i++){
            freqp[p[i]]++;
        }
        vector<int> freqs(256);
        int i = 0;
        int j = 0;
        while(j < s.length()){
            freqs[s[j]]++;
            if(j - i + 1 < p.length()) j++;
            else if(j - i + 1 == p.length()){
                if(freqp == freqs){
                    ans.push_back(i);
                }
                j++;
                freqs[s[i]]--;
                i++;
            }
        }
        return ans;
    }
};