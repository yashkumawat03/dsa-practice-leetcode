class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSum = INT_MAX;
        for(int i = l; i <= r; i++){
            int j = 0; 
            int k = i;
            int sum = 0;
            for(int m = 0; m < i; m++){
                sum += nums[m];
            }
            if(sum > 0) minSum = min(minSum, sum);
            while(k < n){
                sum -= nums[j];
                sum += nums[k];
                if(sum > 0) minSum = min(minSum, sum);
                j++;
                k++;

            }
        }
        return (minSum == INT_MAX) ? -1 : minSum;
    }
};