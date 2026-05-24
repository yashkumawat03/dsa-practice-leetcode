class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mini = INT_MAX;
        if(nums[low] <= nums[high]){
                mini = nums[low];
                return mini;
        }
        while(low <= high){
            int mid = (low + high)/2;
            
            if(nums[mid] >= nums[low]){
                mini = min(mini, nums[low]);
                low = mid+1;
            }
            else{
                mini = min(mini, nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};