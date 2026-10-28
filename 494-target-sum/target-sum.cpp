class Solution {
public:
  int findWays(vector<int> &arr, int target){
        int n = arr.size();
        vector<int> prev(target+1, 0);
        vector<int> cur(target+1, 0);
        
        if(arr[0] == 0) prev[0] = 2;
        else prev[0] = 1;
        if(arr[0] != 0 && arr[0] <= target) prev[arr[0]] = 1;
        
        for(int ind = 1; ind <n; ind++){
            for(int T = 0; T<=target; T++){
                int notTake = prev[T];
                int take = 0;
                if(arr[ind] <= T) take = prev[T-arr[ind]];
               cur[T] = (take + notTake);
            }
            prev = cur;
        }
        return prev[target];
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        
        int totalSum = 0;
        for(auto &it : arr) totalSum += it;
        if(totalSum-diff < 0 || (totalSum-diff) % 2 != 0 ) return 0;
        
        return findWays(arr, (totalSum-diff)/2);                            //div happens before sub, please give appropriate brackets everywhere
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};