class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp = INT_MIN;
        int n = nums.size();
        // for(int i=0;i<n;i++){
        //     int product = 1;
        //     for(int j=i;j<n;j++){
        //         product = product * nums[j];
        //         maxp = max(product,maxp);
        //     }
        // }

        // Optimal Approach 
        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<n;i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxp = max(maxp,max(prefix,suffix));
        }
        return maxp;
    }
};