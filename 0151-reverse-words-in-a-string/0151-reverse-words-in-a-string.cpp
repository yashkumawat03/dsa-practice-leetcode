class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> words;
        for(int i = 0; i < n; i++){
            string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
            }
            if(word.size() > 0){
                words.push_back(word);
            }
        }
        reverse(words.begin(), words.end());
        string ans = "";
        for(int i = 0; i < words.size(); i++){
            if(ans.size() > 0){
                ans += " " + words[i];
            }
            else{
                ans += words[i];
            }
        }
        return ans;
    }
};