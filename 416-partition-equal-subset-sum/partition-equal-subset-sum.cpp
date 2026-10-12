class Solution {
public:
    // bool f(int ind, int target, vector<int> &nums){
    //     if(target == 0) return true;
    //     if(target < 0 || ind >= nums.size() ) return false;

    //     bool included = f(ind+1,target - nums[ind],nums);
    //     bool excluded = f(ind+1,target,nums);
    //     return included || excluded;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;

    //     for(int i =0; i<nums.size(); i++){
    //         sum += nums[i];
    //     }

    //     if( (sum % 2) == 1) return 0;               //odd sum condition

    //     int target = sum/2;
    //     int ind = 0;

    //     return f(ind,target,nums);
    // }


//--------------------------------------------------------------Memoization-------------------------

    //  bool f(int ind, int target, vector<int> &nums,  vector<vector<int>> &dp){
    //     if(target == 0) return true;
    //     if(target < 0 || ind >= nums.size() ) return false;

    //     if(dp[ind][target] != -1) return dp[ind][target];

    //     bool included = f(ind+1,target - nums[ind],nums,dp);
    //     bool excluded = f(ind+1,target,nums,dp);
    //     return dp[ind][target] =  included || excluded;
    // }
    // bool canPartition(vector<int>& nums) {
    //     int sum = 0;
    //     int n = nums.size();
        
    //     for(int i =0; i<n; i++){
    //         sum += nums[i];
    //     }

    //     if( (sum % 2) == 1) return 0;               //odd sum condition

    //     int target = sum/2;
    //     int ind = 0;

    //     vector<vector<int>> dp(n,vector<int>(target+1,-1));

    //     return f(ind,target,nums,dp);
    // }



   
//-----------------------------------------------Tabulation------------------------------
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Target 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // First element
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {

                bool excluded = dp[i - 1][j];

                bool included = false;
                if (nums[i] <= j) {
                    included = dp[i - 1][j - nums[i]];
                }

                dp[i][j] = included || excluded;
            }
        }

        return dp[n - 1][target];
    }


};