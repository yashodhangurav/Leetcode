class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());     //taking uniqe ele

        vector<int> nums2(s.begin(), s.end());          //copying unique ele in nums2

        sort(nums2.begin(), nums2.end());               //ascending sorting

        

        int n = nums.size();
        int m = nums2.size();
vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int  i = 1; i<n+1; i++){
            for(int j = 1; j<m+1; j++){
                if(nums[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};