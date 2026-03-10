class Solution {
public:
    void swap(vector<int>& nums, int i,int j){
        int temp = nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
    //     int red = 0;
    //     int white = 0;
    //     int blue = 0;
    //     for(int i=0;i<n;i++){
    //         if(nums[i]==0) red++;
    //         else if(nums[i]==1) white++;
    //         else blue++;
    //     }
    //     for(int i=0;i<red;i++){
    //         nums[i]=0;
    //     }
    //     for(int i=red;i<red+white;i++){
    //         nums[i]=1;
    //     }
    //     for(int i=red+white;i<n;i++){
    //         nums[i]=2;
    //     }
    // }
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums,low,mid);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums,mid,high);
            high--;
        }
    }
    }
};