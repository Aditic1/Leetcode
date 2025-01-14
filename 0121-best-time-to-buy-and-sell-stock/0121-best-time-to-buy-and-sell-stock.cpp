class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>lowest(n);       // lowest to buy on
        vector<int>highest(n);      // highest to sell on

        lowest[0] = prices[0];
        highest[n-1] = prices[n-1];

        for(int i = 1; i < prices.size(); i++){
            lowest[i] = min(lowest[i-1],prices[i]);
        }

        for(int i = n - 2; i >= 0; i--)
            highest[i] = max(highest[i+1],prices[i]);
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans,highest[i] - lowest[i]);
        }
        return ans;
    }
};