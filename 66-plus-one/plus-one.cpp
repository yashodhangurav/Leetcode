class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        for(int i = nums.size()-1; i>=0; i--){
            if(nums[i] == 9){
                nums[i] = 0;
            }
            else {
                nums[i]++; 
                break;
            } 
        }

        if(nums[0]==0){
            vector<int> res(nums.size()+1, 0);
            res[0] = 1;
            return res;
        }

        return nums;
    }
};