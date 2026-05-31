class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node]=1;
        for(int i=0; i<adj[node].size(); i++){
            auto it=adj[node][i];
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,0);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};
