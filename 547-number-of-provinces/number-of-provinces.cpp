class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;

        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[node][i] == 1 && !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int province = 0;
        vector<int> df;
        int start = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                province++;
                dfs(i, isConnected, vis);
            }
        }

        return province;
    }
};