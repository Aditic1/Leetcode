class Solution {
public:
    int minimumLength(string s) {
        vector<int>freq(26,0);
        for(int i = 0; i < s.length(); i++){
            freq[s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            if(freq[i]!=0)
                ans+=(freq[i]%2)?1:2;
        }
        return ans;
    }
};