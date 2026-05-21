class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int min = INT_MAX;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] >= nums[low]){
                if(nums[low] < min){
                    min = nums[low];
                }  
                low = mid+1;
            }
            else{
                if(nums[mid] < min){
                    min = nums[mid];
                }  
                min = nums[mid];
                high = mid-1;
            }
        }
        return min;
    }
};