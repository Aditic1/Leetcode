class Solution {
public:
    /* Gives TLE at 69/87 */
    int sol1_recursion(int prev, int current, vector<vector<int>>& envelopes){
        if(current==envelopes.size()){
            return 0;
        }

        // exclude
        int exclude = sol1_recursion(prev,current+1,envelopes);

        // include if nothing is present or width and height of the prev < current
        int include = INT_MIN;
        if(prev == -1 || envelopes[prev][0] < envelopes[current][0] and envelopes[prev][1] < envelopes[current][1])
            include = sol1_recursion(current,current+1,envelopes) + 1;
        
        return max(include,exclude);
    }

    /*Solution 2: memoization*/
    /*Gives TLE at 85/87*/
    int sol1_memoization(int prev, int current, vector<vector<int>>& envelopes, vector<vector<int>>&dp){
        if(current==envelopes.size()){
            return 0;
        }
        if(dp[current][prev+1]!=-1)
            return dp[current][prev+1];

        // exclude
        int exclude = sol1_memoization(prev,current+1,envelopes,dp);

        // include if nothing is present or width and height of the prev < current
        int include = INT_MIN;
        if(prev == -1 || envelopes[prev][0] < envelopes[current][0] and envelopes[prev][1] < envelopes[current][1])
            include = sol1_memoization(current,current+1,envelopes,dp) + 1;
        
        dp[current][prev+1] = max(include,exclude);
        return dp[current][prev + 1];
    }

    static bool comp(vector<int>& a, vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        
        vector<int>ans;
        ans.push_back(envelopes[0][1]);

        for(int i = 1; i < n; i++){
            if(ans.back() < envelopes[i][1]) ans.push_back(envelopes[i][1]);
            else{
                int index = lower_bound(ans.begin(),ans.end(),envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1];
            }
        }

        return ans.size();
    }
};