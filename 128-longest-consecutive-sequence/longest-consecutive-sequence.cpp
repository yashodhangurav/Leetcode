class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;

        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(nums[i]);
        }

        int longest = 0;

        for(auto it : s){
            // check if it's the start of a sequence
            if(s.find(it - 1) == s.end()){
                int count = 1;
                int currNum = it;

                // FIXED LOOP
                while(s.find(currNum + 1) != s.end()){
                    currNum++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};