class Solution {
public:

    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        res.push_back(sum);
        }
        return res;
    }
};