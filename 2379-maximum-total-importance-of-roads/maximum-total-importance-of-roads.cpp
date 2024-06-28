class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long res = 0, cost = 1;
        vector<int> connections(n,0);
        for(auto road : roads){
            connections[road[0]]++;
            connections[road[1]]++;
        }
        sort(connections.begin(), connections.end());
        for(auto connection : connections){
            res += connection * (cost++);
        }

        return res;
    }
};