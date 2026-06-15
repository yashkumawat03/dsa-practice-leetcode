class Solution {
public:

int helper(vector<int>& prices, int day, int state,
           vector<vector<int>>& dp)
{
    if(day >= prices.size())
        return 0;

    if(dp[day][state] != -1)
        return dp[day][state];

    int profit = 0;

    if(state == 0)
    {
        int buy = -prices[day] + helper(prices, day + 1, 1, dp);

        int dontBuy = helper(prices, day + 1, 0, dp);

        profit = max(buy, dontBuy);
    }
    else
    {
        int sell = prices[day] + helper(prices, day + 1, 0, dp);

        int dontSell = helper(prices, day + 1, 1, dp);

        profit = max(sell, dontSell);
    }

    return dp[day][state] = profit;
}

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return helper(prices, 0, 0, dp);
}


};
