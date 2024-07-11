#include <vector>
#include <stack>
using namespace std;

class Solution {
private: 
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, stack<int> &st){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, pathVis, st) == true){
                    return true;
                }
            }else if(pathVis[it]){
                return true;
            }
        }

        pathVis[node] = 0;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);
        stack<int> st;
        vector<int> ans;

        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis, st) == true){
                    return {};
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
