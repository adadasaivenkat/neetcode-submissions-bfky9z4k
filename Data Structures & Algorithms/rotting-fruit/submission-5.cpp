class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        int minutes=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int size=q.size();
            bool rotted=false;
            while(size>0){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                        grid[nr][nc]=2;
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        rotted=true;
                    }
                }
                size--;
            }
            if(rotted) minutes++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && vis[i][j]==0) return -1;
            }
        }
        return minutes;
    }
};