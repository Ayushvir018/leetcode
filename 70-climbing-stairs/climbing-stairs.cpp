// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) return n;

//         int a = 1, b = 2;

//         for (int i = 3; i <= n; i++) {
//             int c = a + b;
//             a = b;
//             b = c;
//         }

//         return b;
//     }
// };

class Solution {
public:
    int climbStairs(int n) {

        int dp[46];

        for (int i = 0; i <= n; i++)
            dp[i] = -1;

        return solve(n, dp);
    }

    int solve(int n, int dp[]) {

        if (n <= 2)
            return n;

        if (dp[n] != -1)
            return dp[n];

        int f1 = solve(n - 1, dp);
        int f2 = solve(n - 2, dp);

        dp[n] = f1 + f2;

        return dp[n];
    }
}; 