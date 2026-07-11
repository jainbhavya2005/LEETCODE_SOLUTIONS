class Solution {
   void  dfs(int node, vector<vector<int>>& adj, vector<int>& vis,vector<int>& v) {
        vis[node] = 1;
        v.push_back(node);
        for (int it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, v);
            }
        }
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
                vector<int> component;
                dfs(i, adj, vis, component);
                bool complete = true;
                int sz = component.size();
                for (int node : component) {
                    if (adj[node].size() != sz - 1) {
                        complete = false;
                        break;
                    }
                }

                if (complete)
                    count++;
            }
        }

            return count;
        }
    };