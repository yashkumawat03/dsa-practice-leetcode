class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
         set<pair<int,int>> st;
        // for(int i = 0;i<n-1;i++){
        //     for(int j =i+1; j<n; j++){
        //         int diff = abs(nums[i]-nums[j]);
        //         if(diff == k)
        //             st.insert({min(nums[i],nums[j]), max(nums[i],nums[j])});
        //     }
        // }
        // return st.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 1;
        while(j < n){
            if(i==j){
                j++;
                continue;
            }
            int diff = nums[j]-nums[i];
            if(diff == k){
                st.insert({nums[i],nums[j]});
                i++;
                j++;
            }
                
            else if(diff > k)
                i++;
            else 
                j++;
        }
        return st.size();
    }
};