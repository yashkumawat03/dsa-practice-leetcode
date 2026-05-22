class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int,int>> st;
        for(int i = 0;i<n-1;i++){
            for(int j =i+1; j<n; j++){
                int diff = abs(nums[i]-nums[j]);
                if(diff == k)
                    st.insert({min(nums[i],nums[j]), max(nums[i],nums[j])});
            }
        }
        return st.size();
    }
};