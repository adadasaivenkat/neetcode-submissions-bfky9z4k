class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        const int INF=2147483647; 
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dist=0;
        while(!q.empty()){
            int size=q.size();
            dist++;
            while(size--){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==INF && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        grid[nr][nc]=dist;
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};