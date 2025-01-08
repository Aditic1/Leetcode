class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with INT_MAX
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Set distance to 0 for self-loops
        for (int i = 0; i < n; i++) 
            dist[i][i] = 0;

        // Fill initial distances based on edges
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;  // Since the graph is undirected
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find the city with the minimum number of reachable neighbors
        int minNeighbors = INT_MAX;
        int city = -1;

        for (int i = 0; i < n; i++) {
            int count = 0;  // Count reachable neighbors
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            // Update result if fewer neighbors or higher city index
            if (count <= minNeighbors) {
                minNeighbors = count;
                city = i;
            }
        }

        return city;
    }
};
