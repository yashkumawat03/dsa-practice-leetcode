class Solution {
public:
    int lowerbound(vector<int> &nums, int n , int target){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int upperbound(vector<int> &nums, int n , int target){
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // Time Complexity - O(N)
        // int first = -1, last = -1;
        // for(int i=0;i<n;i++){
        //     if(nums[i] == target){
        //         if(first == -1)
        //             first = i;
        //         last = i;
        //     }
        // }
        // return {first,last};

        int lb = lowerbound(nums,n,target);
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb, upperbound(nums,n,target)-1};
    }
};