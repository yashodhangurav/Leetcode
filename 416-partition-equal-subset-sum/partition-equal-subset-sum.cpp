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

     bool f(int ind, int target, vector<int> &nums,  vector<vector<int>> &dp){
        if(target == 0) return true;
        if(target < 0 || ind >= nums.size() ) return false;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool included = f(ind+1,target - nums[ind],nums,dp);
        bool excluded = f(ind+1,target,nums,dp);
        return dp[ind][target] =  included || excluded;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        
        for(int i =0; i<n; i++){
            sum += nums[i];
        }

        if( (sum % 2) == 1) return 0;               //odd sum condition

        int target = sum/2;
        int ind = 0;

        vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return f(ind,target,nums,dp);
    }
};