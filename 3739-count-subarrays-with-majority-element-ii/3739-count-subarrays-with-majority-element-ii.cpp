class Solution {
public:
    class BIT {
    public:
        vector<int> tree;
        int n;

        BIT(int n) {
            this->n = n;
            tree.resize(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                tree[idx] += val;
                idx += idx & -idx;
            }
        }

        int query(int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += tree[idx];
                idx -= idx & -idx;
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        int offset = n + 2;
        BIT bit(2 * n + 5);

        long long ans = 0;
        int pref = 0;

        bit.update(offset, 1); // prefix sum = 0

        for (int x : nums) {
            if (x == target)
                pref += 1;
            else
                pref -= 1;

            ans += bit.query(pref + offset - 1);

            bit.update(pref + offset, 1);
        }

        return ans;
    }
};