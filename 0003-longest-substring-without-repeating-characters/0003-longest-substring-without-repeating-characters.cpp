class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>
            existingChar; // existing characters in the current substring

        /**
         * abcabb
         * pwwkew
         * dabcbd -> left = 0; current substring = ""; maxLen = max(maxLen,
         * currentLen)
         *
         * left = 0.
         * i = 0; st -> does it exist in st? if not -> unique -> current
         * substring; currentLen = i - left + 1 i = 1; st -> a doesn't exist -
         * add it as well -> currentLen = left - i + 1 = 2 i = 2, st -> b
         * doesn't exist  - currentLen = 3 i = 3; st -> c doesn't exist - add it
         * as well - currentLen = 4 i = 4; st -> b already exists.
         *
         *      while(st.count(s[i])!=0){
         *          st.erase(s[left]);
         *          left++
         *      }
         *  finally all occurences of d, a, b are removed -> left = 3
         *  currentLen = right/i - left + 1 = 4-3+1 = 2;
         *
         * i = 5; st -> d is not present
         *
         */

        int left = 0, currLen = 0, maxLen = 0;

        for (int i = 0; i < s.length();) {
            
            if (existingChar.find(s[i]) != existingChar.end()) {
                currLen = i - left;
                maxLen = max(currLen, maxLen);

                while (existingChar.count(s[i])) {
                    existingChar.erase(s[left]);
                    left++;
                }
            }else{
                existingChar.insert(s[i]);
                i++;
            }
        }

        currLen = s.length() - left;
        maxLen = max(currLen, maxLen);

        return maxLen;
    }
};