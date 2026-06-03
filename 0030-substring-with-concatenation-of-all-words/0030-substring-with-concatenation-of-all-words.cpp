class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int len = words[0].size();
        unordered_map<string, int> mp;
        vector<int> ans;
        for(auto str : words){
            mp[str]++;
        }
        for(int i=0; i<len; i++){
            int left = i, right = i;
            unordered_map<string , int> winMp;
            int count = 0;
            while(right <= n - len){
                string temp = s.substr(right,len);
                if(mp.find(temp) != mp.end()){
                    winMp[temp]++;
                    count++;
                    while(winMp[temp] > mp[temp]){
                        string leftStr = s.substr(left, len);
                        winMp[leftStr]--;
                        left += len;
                        count--;
                    }
                    if(count == words.size()){
                        ans.push_back(left);
                    }
                }
                else{
                    left = right + len;
                    count = 0;
                    winMp.clear();
                }
                right += len;
            }
        }
        return ans;
    }
};