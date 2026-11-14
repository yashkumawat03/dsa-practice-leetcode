class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {

        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        // Build prefix sum
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        multiset<long long> st;
        long long minSum = LLONG_MAX;

        for(int i = l; i <= n; i++) {

            // Add valid starting prefix
            st.insert(prefix[i - l]);

            // Remove starting prefixes outside the window
            if(i - r - 1 >= 0) {
                auto it = st.find(prefix[i - r - 1]);
                st.erase(it);
            }

            // Find the largest prefix sum strictly smaller
            // than the current prefix sum
            auto it = st.lower_bound(prefix[i]);

            if(it != st.begin()) {
                --it;

                long long sum = prefix[i] - *it;

                minSum = min(minSum, sum);
            }
        }

        return minSum == LLONG_MAX ? -1 : (int)minSum;
    }
};