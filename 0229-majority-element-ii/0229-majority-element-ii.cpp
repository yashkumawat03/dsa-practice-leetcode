class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        // for(int i=0;i<n;i++){
        //     if(ans.size()==0 || ans[0]!=nums[i]){
        //         int element = nums[i];
        //         int cnt = 1;
        //         for(int j=i+1;j<n;j++){
        //             if(nums[i]==nums[j]){
        //             cnt++;
        //             }
        //         }
        //         if(cnt>n/3)  ans.push_back(nums[i]);
        //     }
        //     if(ans.size()==2) break;
        // }
        unordered_map<int,int> mpp;
        int min = n/3+1;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]==min) ans.push_back(nums[i]);
            if(ans.size()==2) break;
            
        }
        // for(auto it : mpp){
        //     if(it.second>n/3) ans.push_back(it.first);
        // }
        return ans;
    }
};