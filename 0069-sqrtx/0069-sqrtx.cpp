class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        long long low = 1, high = x, ans = 0;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;
            if(val == x){
                return mid;
            }
            else if(val < x) {
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};