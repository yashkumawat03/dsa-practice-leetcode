class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = n2 - 1; i >= 0; i--){
            if(st.empty()){
                st.push(nums2[i]);
            }
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            mp[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }
        for(auto x : nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};