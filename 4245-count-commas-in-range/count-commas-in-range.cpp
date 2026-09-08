class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;
        long long start = 1000;
        long long commas = 1;

        while (start <= n) {
            long long end = start * 1000 - 1;
            
            ans += (min((long long)n, end) - start + 1) * commas;
            
            start *= 1000;
            commas++;
        }

        return ans;
    }
};