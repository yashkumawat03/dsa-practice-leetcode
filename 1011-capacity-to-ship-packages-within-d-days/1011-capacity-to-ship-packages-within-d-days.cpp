class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        if(days == 1) return high;
        int sum = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int d = 1;
            int sum = 0;
            for(int i : weights){
                if(sum + i > mid){
                    d++;
                    sum = i;
                }
                else{
                    sum += i;
                }
            }
            if(d <= days){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};