class Solution {
private:
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node]=1;
        // here, i is neighbour of node
        for(int i=0; i<isConnected[node].size(); i++){
            if(isConnected[node][i]==1 && i!=node){
                if(!vis[i]){
                    dfs(i,isConnected,vis);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cnt=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};