class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> max_Freq(26, 0); 
        vector<int> temp(26, 0);
        
        // Calculate the maximum frequency for each character across all words in words2
        for (const string& word : words2) {
            fill(temp.begin(), temp.end(), 0);
            for (char ch : word) {
                temp[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                max_Freq[i] = max(max_Freq[i], temp[i]);
            }
        }
        
        vector<string> universalWords;
        
        // Check each word in words1
        for (const string& word : words1) {
            fill(temp.begin(), temp.end(), 0);
            for (char ch : word) {
                temp[ch - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (max_Freq[i] > temp[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        return universalWords;
    }
};
