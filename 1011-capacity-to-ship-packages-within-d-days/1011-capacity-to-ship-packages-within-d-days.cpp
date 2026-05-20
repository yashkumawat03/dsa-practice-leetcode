class Solution {
public:
    bool ispossible(vector<int> &weights, int mid, int days){
        int day = 1;
        int shipload = 0;
        for(int i=0; i<weights.size();){
            if(shipload + weights[i] <= mid){
                shipload += weights[i];
                i++;
            }
            else{
                day++;
                shipload = 0;
            }
            if(day > days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans;
        int total = 0;
        for(int i=0;i<n;i++){
            total += weights[i];
        }
        int s = 1, e = total;
        while(s<=e){
            int mid = (s+e)/2;
            if(ispossible(weights,mid,days)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};