class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> a;

        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < words.size(); j++) {
                if(i != j && words[j].find(words[i]) != string::npos) {
                    a.insert(words[i]); 
                }
            }
        }

        // Convert set to vector
        return vector<string>(a.begin(), a.end());
    }
};
