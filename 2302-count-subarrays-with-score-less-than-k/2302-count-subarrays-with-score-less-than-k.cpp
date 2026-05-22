class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0;
        int n = nums.size();
        long long sum = 0;
        long long count = 0;
        while(j<n){
            sum += nums[j];
            long long ans = sum * (j-i+1);
            while(i<=j && ans >= k){
                sum -= nums[i];
                i++;
                ans =sum*(j-i+1);
                
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
};