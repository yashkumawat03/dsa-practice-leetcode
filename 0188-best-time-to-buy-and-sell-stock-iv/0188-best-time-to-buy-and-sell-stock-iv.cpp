class Solution {
public:
    int solve(int day, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(day == prices.size() || cap == 0)
            return 0;

        if(dp[day][buy][cap] != -1)
            return dp[day][buy][cap];

        int profit;

        if(buy){
            int buyStock = -prices[day] + solve(day+1, 0, cap, prices, dp);

            int skip = solve(day+1, 1, cap, prices, dp);

            profit = max(buyStock, skip);
        }
        else{
            int sellStock = prices[day] + solve(day+1, 1, cap-1, prices, dp);

            int hold = solve(day+1, 0, cap, prices, dp);

            profit = max(sellStock, hold);
        }

        return dp[day][buy][cap] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(k+1, -1)));

        return solve(0, 1, k, prices, dp);
    }
};