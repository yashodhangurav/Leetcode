class Solution {
public:
    int climbStairsMem(int n, vector<int> &dp){
        if(n == 0 || n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = climbStairsMem(n-1, dp) + climbStairsMem(n-2,dp);
        return dp[n];

    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);

       return climbStairsMem(n, dp);
    }
};