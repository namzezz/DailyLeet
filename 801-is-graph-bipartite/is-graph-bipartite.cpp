class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]){
        color[node] = col;

        for(auto it : adj[node]){
            if(color[it] == -1){
                if(!dfs(it, !col, color, adj)){
                    return false;
                } 
            } else if (color[it] == col){
                    return false;
                }
            }

            return true;
        }


        

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> adj[n];

        // Construct the adjacency list from the graph
        for(int i = 0 ; i < n ; i++){
            for(int j : graph[i]){
                adj[i].push_back(j);
            }
        }

        
        int color[n];

        for(int i = 0 ; i < n ; i++){
           color[i] = -1;
        }

        for(int i = 0 ; i < n ; i++){
            if(color[i] == -1){
                if(dfs(i, 0, color, adj)==false){
                    return false;
                }
            }
        }

        return true;
    }
};