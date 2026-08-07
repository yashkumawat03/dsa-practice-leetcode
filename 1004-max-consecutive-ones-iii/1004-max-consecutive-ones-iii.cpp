class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int max_len = 0;
        int zeros = 0;
        while(j < n){
            if(nums[j] == 0) zeros++;
            while(zeros > k){
                if(nums[i] == 0) zeros--;
                i++;
            }
            if(zeros <= k){
                max_len = max(j - i + 1, max_len);
            }
            j++;
        }
        return max_len;
    }
};