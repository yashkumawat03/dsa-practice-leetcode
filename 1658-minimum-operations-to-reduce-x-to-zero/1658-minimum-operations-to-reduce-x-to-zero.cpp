class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        int left = 0;
        int right = 0;
        int reqSum = totalSum - x;
        int winSum = 0;
        int operations = -1;
        while(right < n){
            winSum += nums[right];
            while(left <= right && winSum > reqSum){
                winSum -= nums[left];
                left++;

            }
            if(winSum == reqSum){
                operations = max((right-left+1), operations);
            }
            right++;
        }
        return operations == -1 ? -1  : n - operations;
    }
};