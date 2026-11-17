class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n - 1];
        int maxProfit = INT_MIN;
        for(int i = n - 2; i >= 0; i--){
            int rem = maxi - prices[i];
            maxProfit = max(maxProfit, rem);
            maxi = max(prices[i], maxi);
        }
        return (maxProfit < 0) ? 0 : maxProfit;
    }
};