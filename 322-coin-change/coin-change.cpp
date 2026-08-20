class Solution {
public:
    int solve(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;

        if (i == coins.size() || amount < 0)
            return 1e9;

        if (dp[i][amount] != -1)
            return dp[i][amount];

        // Pick: same coin can be used again
        int pick = 1 + solve(coins, amount - coins[i], i, dp);

        // Skip: move to next coin
        int skip = solve(coins, amount, i + 1, dp);

        return dp[i][amount] = min(pick, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));

        int ans = solve(coins, amount, 0, dp);

        return (ans >= 1e9) ? -1 : ans;
    }
};