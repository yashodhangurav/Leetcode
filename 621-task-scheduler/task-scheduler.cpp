class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task (A–Z)
        vector<int> freq(26, 0);
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Step 2: Find the maximum frequency
        int maxFreq = *max_element(freq.begin(), freq.end());

        // Step 3: Count how many tasks have this max frequency
        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) {
                maxCount++;
            }
        }

        // Step 4: Calculate structure of scheduling
        int gaps = maxFreq - 1;        // number of gaps between most frequent tasks
        int gapSize = n + 1;           // each gap size (including the task itself)

        int minSlotsNeeded = gaps * gapSize + maxCount;

        // Step 5: Final answer
        // Either:
        // - we use all tasks (no idle needed)
        // - or we need idle slots
        return max((int)tasks.size(), minSlotsNeeded);
    }
};