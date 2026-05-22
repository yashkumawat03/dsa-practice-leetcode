class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> mpp;
        for(int i = 1;i<n;i++){
            if(mpp[nums[i] + nums[i-1]]== true) return true;
            mpp[nums[i] + nums[i-1]]= true;
        }
        return false;
    }
};