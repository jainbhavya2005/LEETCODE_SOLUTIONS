class Solution {
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& v) {
        vis[node] = 1;
        v.push_back(node);
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, v);
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (adj[v[i]].size() != v.size() - 1) {
                return false;
            }
        }
        return true;
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> v;
                if (dfs(i, adj, vis, v) == true) {
                    count++;
                }
            }}

            return count;
        }
    };