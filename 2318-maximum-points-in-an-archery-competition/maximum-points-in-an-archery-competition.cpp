#include <vector>
#include <algorithm>

class Solution {
private:
    int maxPoints = -1;
    std::vector<int> bestBobArrows;

    void dfs(int index, int remainingArrows, int currentPoints, std::vector<int>& currentBobArrows, const std::vector<int>& aliceArrows) {
        // Base case: if we have checked all sections from 11 down to 0
        if (index < 0 || remainingArrows == 0) {
            if (currentPoints > maxPoints) {
                maxPoints = currentPoints;
                bestBobArrows = currentBobArrows;
                // If there are any leftover arrows, add them to section 0
                bestBobArrows[0] += remainingArrows;
            }
            return;
        }

        // Option 1: Try to win the current section 'index' (if Bob has enough arrows)
        int requiredArrows = aliceArrows[index] + 1;
        if (remainingArrows >= requiredArrows) {
            currentBobArrows[index] = requiredArrows;
            dfs(index - 1, remainingArrows - requiredArrows, currentPoints + index, currentBobArrows, aliceArrows);
            currentBobArrows[index] = 0; // Backtrack
        }

        // Option 2: Skip winning the current section (spend 0 arrows on it)
        dfs(index - 1, remainingArrows, currentPoints, currentBobArrows, aliceArrows);
    }

public:
    std::vector<int> maximumBobPoints(int numArrows, std::vector<int>& aliceArrows) {
        maxPoints = -1;
        std::vector<int> currentBobArrows(12, 0);
        bestBobArrows.assign(12, 0);

        dfs(11, numArrows, 0, currentBobArrows, aliceArrows);

        return bestBobArrows;
    }
};