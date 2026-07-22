#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            int num = arr[i];

            if (freq.count(num)) {
                freq[num] = freq[num] + 1;
            } else {
                freq[num] = 1;
            }
        }

        // Step 2: Check uniqueness
        unordered_set<int> seenFreq;

        for (auto it = freq.begin(); it != freq.end(); it++) {
            int count = it->second;

            if (seenFreq.count(count)) {
                return false; // duplicate frequency
            }

            seenFreq.insert(count);
        }

        return true;
    }
};