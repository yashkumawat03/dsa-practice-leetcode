class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.length(); i++) {

            // Opening brackets
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }

            // Closing brackets
            else {

                // No matching opening bracket
                if(st.empty()) {
                    return false;
                }

                char top = st.top();

                // Matching pairs
                if((s[i] == ')' && top == '(') ||
                   (s[i] == '}' && top == '{') ||
                   (s[i] == ']' && top == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};