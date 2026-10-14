class Solution {
public:
// int f(int ind,vector<int>& coins, int target, vector<vector<int>> &dp){
//     if(ind == 0){
//         if(target % coins[ind] == 0) return target/coins[ind];
//         else return 1e9;
//     }

//     if(dp[ind][target] != -1) return dp[ind][target];

//     int notTake = 0 + f(ind-1,coins,target,dp);
//     int take = INT_MAX;
//     if(coins[ind] <=target){
//          take = 1 + f(ind,coins,target-coins[ind],dp);
//     }
//     return dp[ind][target] =  min(notTake,take);
// }



    int coinChange(vector<int>& coins, int target) {
        int n = coins.size();

        vector<vector<int>> dp(n,vector<int>(target+1,0));

       for(int T = 0; T<=target; T++){
        if( T % coins[0] == 0 )  dp[0][T] = T/coins[0];
        else dp[0][T] = 1e9;
       }

       for(int ind = 1; ind < n; ind++){
        for(int T = 0; T<=target; T++){
            int notTake = 0 + dp[ind-1][T];
            int take = 1e9;

            if(coins[ind] <= T){
                take = 1 + dp[ind][T - coins[ind]];
            }
            dp[ind][T] = min(notTake,take);
        }
       }
        int ans = dp[n - 1][target];

        if (ans >= 1e9) return -1;

        return ans;
    }
};