class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int, int> src = {0, 0};
        pair<int, int> dest = {n - 1, m - 1};

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) {
            return -1; // If start or end is blocked, there's no path.
        }

        if (src == dest) {
            return 1;
        }

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[src.first][src.second] = 1;
        q.push({1, {src.first, src.second}});

        // 8 directional so loop i j from -1 to 1;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newr = r + i;
                    int newc = c + j;

                    if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                        grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]) {
                        dist[newr][newc] = dis + 1;
                        if (newr == dest.first && newc == dest.second) {
                            return dis + 1;
                        }
                        q.push({dis + 1, {newr, newc}});
                    }
                }
            }
        }

        return -1;
    }
};