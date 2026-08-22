// Iterative DFS
class Solution {
private:
    int dr[4]={0,-1,0,1};
    int dc[4]={-1,0,1,0};
    void dfs(vector<vector<char>>& grid, vector<vector<int>> &vis,
    int n, int m, int row, int col){
        stack<pair<int,int>> stk;
        stk.push({row,col});
        while(!stk.empty()){
            int r=stk.top().first;
            int c=stk.top().second;
            stk.pop();
            if(vis[r][c]) continue;
            vis[r][c]=1;
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                    stk.push({nr,nc});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(grid,vis,n,m,i,j);
                    cnt+=1;
                }

            }
        }
        return cnt;
    }
};