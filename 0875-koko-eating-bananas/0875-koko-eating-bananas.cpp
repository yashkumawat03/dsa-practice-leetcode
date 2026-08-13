class Solution {
public:
    long long fun(vector<int> &piles, int mid){
        long long reqtime = 0;
        for(int i = 0; i < piles.size(); i++){
            reqtime += ceil((double) piles[i]/mid);
        }
        return reqtime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int mini = 0;
        while(low <= high){
            int mid = (low + (high - low) / 2);
            long long time = fun(piles, mid);
            if(time <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};