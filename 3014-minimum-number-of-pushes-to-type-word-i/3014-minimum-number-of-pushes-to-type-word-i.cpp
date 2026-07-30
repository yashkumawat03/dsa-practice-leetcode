class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        int push = 1;
        for(int i = 0; i < n; i++){
            if(i % 8 == 0 && i != 0){
                push++;
            }
            ans += push;
        }
        return ans;
    }
};