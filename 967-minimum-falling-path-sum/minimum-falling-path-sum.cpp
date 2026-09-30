class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m));

        // First row
        for(int j = 0; j < m; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Remaining rows
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < m; j++) {

                int up = dp[i-1][j];

                int leftDiagonal = 1e9;
                if(j > 0)
                    leftDiagonal = dp[i-1][j-1];

                int rightDiagonal = 1e9;
                if(j < m-1)
                    rightDiagonal = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] +
                           min(up, min(leftDiagonal, rightDiagonal));
            }
        }

        // Minimum value in last row
        int ans = 1e9;

        for(int j = 0; j < m; j++) {
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};