class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adj(n);

    for(auto &e : edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<bool> vis(n, false);

    if(dfs(0, -1, adj, vis))
        return false; // cycle

    for(bool v : vis){
        if(!v) return false; // disconnected
    }

    return true;
}
bool dfs(int node,
         int parent,
         vector<vector<int>>& adj,
         vector<bool>& vis) {

    vis[node] = true;

    for(int nei : adj[node]) {

        if(!vis[nei]) {
            if(dfs(nei, node, adj, vis))
                return true;      // cycle found below
        }
        else if(nei != parent) {
            return true;          // visited node that's not parent
        }
    }

    return false;
}
};
