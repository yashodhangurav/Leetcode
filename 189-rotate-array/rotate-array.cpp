class Solution {
public:

void reverseArr(vector<int>& nums, int start, int end) {
    while (start < end) {
        swap(nums[start], nums[end]);
        start++, end--;
    }
}
    void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;       // very important!

    // Step 1
    reverseArr(nums, 0, n - 1);
    // Step 2
    reverseArr(nums, 0, k - 1);
    // Step 3
    reverseArr(nums, k, n - 1);
        
    
    }
};