class Solution {
public:
    int max(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i = 0;i<piles.size();i++){
            if(piles[i] > maxi){
                maxi = piles[i];
            }
        }
        return maxi;
    }
    long long func(vector<int>& piles, int mid){
        long long time = 0;
        for(int i=0;i<piles.size();i++){
            time += ceil(double(piles[i])/double(mid));
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = max(piles);
        //int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long required_time = func(piles,mid);
            if(required_time <= h){
                //ans = min(mid,ans);
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return low;
    }
};