
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0) {
                    cnt++;
                }
            }

            for (int j = budget; j >= price; j--) {
                if (dp[j - price] != -1e9) {
                    dp[j] = max(dp[j], dp[j - price] + cnt);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i <= budget; i++) {
            if (dp[i] != -1e9) {
                ans = max(ans, dp[i] + (budget - i) / minPrice);
            }
        }

        return ans;
    }
};
