class Solution {
public:
    int func(vector<int>& weights, int mid){
        int sum = 0;
        int days = 1;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > mid){
                days++;
                sum = weights[i];
            }
            else sum += weights[i];
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        while(low <= high){
            int mid = low + (high - low) / 2;
            int d = func(weights, mid);
            if(d <= days) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};