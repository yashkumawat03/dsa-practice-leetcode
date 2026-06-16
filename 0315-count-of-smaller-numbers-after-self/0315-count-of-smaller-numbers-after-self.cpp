#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        ordered_set st;
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--) {
            ans[i] = st.order_of_key({nums[i], i});
            st.insert({nums[i], i});
        }

        return ans;
    }
};