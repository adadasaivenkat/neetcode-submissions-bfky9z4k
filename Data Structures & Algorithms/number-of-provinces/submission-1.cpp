class Solution {
private:
    void bfs(int startNode, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[startNode]=1;
        queue<int> q;
        q.push(startNode);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            // here, i is neighbour of node
            for(int i=0; i<isConnected[node].size(); i++){
                if(isConnected[node][i]==1 && i!=node){
                    if(!vis[i]){
                        q.push(i);
                        vis[i]=1;
                    }
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
                bfs(i,isConnected,vis);
                cnt++;
            }
        }
        return cnt;
    }
};