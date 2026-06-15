class Solution {
public:


int helper(vector<int>& prices, int fee,
           int day, int state,
           vector<vector<int>>& dp)
{
    if(day >= prices.size())
        return 0;

    if(dp[day][state] != -1)
        return dp[day][state];

    int profit = 0;

    if(state == 0)
    {
        int buy =
            -prices[day] +
            helper(prices, fee, day + 1, 1, dp);

        int skip =
            helper(prices, fee, day + 1, 0, dp);

        profit = max(buy, skip);
    }
    else
    {
        int sell =
            prices[day] - fee +
            helper(prices, fee, day + 1, 0, dp);

        int hold =
            helper(prices, fee, day + 1, 1, dp);

        profit = max(sell, hold);
    }

    return dp[day][state] = profit;
}

int maxProfit(vector<int>& prices, int fee) {

    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return helper(prices, fee, 0, 0, dp);
}

};
