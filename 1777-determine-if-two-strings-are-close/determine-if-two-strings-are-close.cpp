class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size())
            return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        for(char c : word1)
            freq1[c - 'a']++;

        for(char c : word2)
            freq2[c - 'a']++;

        // Check if both words use the exact same set of characters
        for(int i = 0; i < 26; i++){
            if((freq1[i] > 0 && freq2[i] == 0) ||
               (freq1[i] == 0 && freq2[i] > 0)){
                return false;
            }
        }

        // Sort frequency distribution
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
    
};