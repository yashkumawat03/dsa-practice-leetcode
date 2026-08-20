class Solution {
public:
    bool func(vector<int> &nums, long long mid, int k){
        int subarray = 1;
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(maxSum + nums[i] <= mid){
                maxSum += nums[i];
            }
            else{
                maxSum = nums[i];
                subarray++;
            }
        }
        return subarray <= k; 
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(),0LL);
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(func(nums, mid, k) == true)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};