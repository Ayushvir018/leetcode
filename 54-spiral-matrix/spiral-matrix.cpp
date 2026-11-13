class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int startrow = 0;
        int endrow = row - 1;
        int startcol = 0;
        int endcol = col - 1;

        while(count < total) {

            // top row
            for(int i = startcol; i <= endcol && count < total; i++) {
                ans.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;

            // right column
            for(int i = startrow; i <= endrow && count < total; i++) {
                ans.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;

            // bottom row
            for(int i = endcol; i >= startcol && count < total; i--) {
                ans.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;

            // left column
            for(int i = endrow; i >= startrow && count < total; i--) {
                ans.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }

        return ans;
    }
};