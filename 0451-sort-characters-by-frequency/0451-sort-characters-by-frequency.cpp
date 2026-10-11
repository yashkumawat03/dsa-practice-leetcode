class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        string result = "";
        while(!freq.empty()){
            char maxchar;
            int maxfreq = 0;
            for(auto &it : freq){
                if(it.second > maxfreq){
                    maxchar = it.first;
                    maxfreq = it.second;
                }
            }
            result += string(maxfreq, maxchar);
            freq.erase(maxchar);
        }
        
        return result;
    }
};