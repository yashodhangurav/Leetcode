class Solution {
public:
    // int f(int ind, int tranNo, vector<int> &prices, int n, int k,  vector<vector<int>> &dp){
    //     if(ind == n || tranNo == 2*k) return 0;
    //     if(dp[ind][tranNo] != -1) return dp[ind][tranNo];

    //     if(tranNo % 2 == 0) //buy
    //     {
    //         return dp[ind][tranNo] =  max( -prices[ind] + f(ind+1,tranNo+1,prices,n,k,dp),
    //                         0 + f(ind+1, tranNo,prices,n,k,dp));
    //     }
    //     return dp[ind][tranNo] =  max(prices[ind] + f(ind+1,tranNo+1,prices,n,k,dp),
    //                 0 + f(ind+1, tranNo,prices,n,k,dp));
    // }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*k+1, 0));

        for(int ind = n-1; ind>=0; ind--){
            for(int tranNo = 2*k-1; tranNo >= 0; tranNo--){
                if(tranNo % 2 == 0){ //buy
                dp[ind][tranNo] = max( -prices[ind] + dp[ind+1][tranNo+1], 
                                                    0 + dp[ind+1][tranNo]);
                }
                else dp[ind][tranNo] = max( prices[ind] + dp[ind+1][tranNo+1],
                                            0 + dp[ind+1][tranNo]);
            }
        }
        return dp[0][0];
    }
};