class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;

        for (int i = 0, j = height.size() - 1; i < j; ) {

            int cap = min(height[i], height[j]) * (j - i);
            maxi = max(maxi, cap);

            if (height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return maxi;
    }
};