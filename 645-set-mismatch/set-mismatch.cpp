class Solution {
public:

    vector<int> findErrorNums(vector<int>& nums) {
         int n = nums.size();
         vector<int> freq(n+1, 0);

         for(int val : nums){   
            freq[val]++;
        }
        int missing,repeating;
         for(int i = 1; i<=n; i++){
             if(freq[i] == 0) missing = i;
             else if(freq[i]>1) repeating = i;
        }
    return {repeating, missing};
    }
};