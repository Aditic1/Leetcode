class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> arr(26, vector<int>(26, INT_MAX)); 
        int n = 26;

        // Initialize the diagonal to 0 (cost to transform a character to itself is 0)
        for (int i = 0; i < n; i++) {
            arr[i][i] = 0;
        }

        // Fill the transformation costs
        for (int i = 0; i < original.size(); i++) {
            arr[original[i] - 'a'][changed[i] - 'a'] = min(arr[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        // Apply Floyd-Warshall to calculate the shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (arr[i][k] != INT_MAX && arr[k][j] != INT_MAX) {
                        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                    }
                }
            }
        }

        // Calculate the total cost for the transformation
        long long ans = 0;
        for (int i = 0; i < source.size(); i++) {
            int src = source[i] - 'a';
            int tgt = target[i] - 'a';

            // If there's no valid transformation, return -1
            if (arr[src][tgt] == INT_MAX) {
                return -1;
            }
            ans += arr[src][tgt];
        }

        return ans;
    }
};
