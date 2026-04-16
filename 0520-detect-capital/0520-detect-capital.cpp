class Solution {
public:
    bool detectCapitalUse(string word) {
         int n = word.size();

        // Case 1: All capitals
        bool allUpper = true;
        for (char c : word) {
            if (!isupper(c)) {
                allUpper = false;
                break;
            }
        }

        // Case 2: All small letters
        bool allLower = true;
        for (char c : word) {
            if (!islower(c)) {
                allLower = false;
                break;
            }
        }

        // Case 3: First letter capital, rest small
        bool firstUpperRestLower = isupper(word[0]);
        for (int i = 1; i < n; i++) {
            if (!islower(word[i])) {
                firstUpperRestLower = false;
                break;
            }
        }

        return allUpper || allLower || firstUpperRestLower;
    }
};