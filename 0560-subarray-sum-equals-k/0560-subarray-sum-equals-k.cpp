class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
        
        int n = nums.size();
        int sum = 0;
        int cnt = 0;
        map<int,int> presumMap;
        presumMap[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum - k;
            cnt += presumMap[rem];
            presumMap[sum]+=1;
        }
        return cnt;
    }
};