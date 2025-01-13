class Solution {
public:
    int ans = 0;
    bool isPalind(string s){
        int j = s.length() - 1; int i = 0;

        while(i < j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    void backtrack(string s, string&s1, string &s2, int index){
        if(index>=s.length()){
            if(isPalind(s1) and isPalind(s2))
                ans = max(ans, (int)s1.length() * (int)s2.length());
            return;
        }

        // include current index in s1 and not in s2
        s1.push_back(s[index]);
        backtrack(s,s1,s2,index+1);
        s1.pop_back();

        // include current index in s2 and not in s1
        s2.push_back(s[index]);
        backtrack(s,s1,s2,index+1);
        s2.pop_back();

        //exclude in both
        backtrack(s,s1,s2,index+1);
    }
    int maxProduct(string s) {
        string s1 = "",s2 = "";
        backtrack(s,s1,s2,0);
        return ans;
    }
};