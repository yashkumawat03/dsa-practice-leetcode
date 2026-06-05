class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st1;
        vector<int> left(n);
        vector<int> right(n);
        
        // left minimum index
        for(int i = 0; i < n; i++){
            while(!st1.empty() && heights[st1.top()] >= heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                left[i] = -1;
            }
            else{
                left[i] = st1.top();
            }
            st1.push(i);
        }

        stack<int> st2;
        for(int i = n-1; i >= 0; i--){
            while(!st2.empty() && heights[st2.top()] >= heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                right[i] = n;
            }
            else{
                right[i] = st2.top();
            }
            st2.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i]  - 1;
            ans = max(ans, width * heights[i]);
        }
        return ans;
    }
};