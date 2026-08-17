class Solution {
private:
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    bool dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, 
    int n, int m, string& word, int idx){
        if(idx==word.size()) return true;
        vis[r][c]=1; // Mark this cell as visited in the CURRENT path
        // Explore -> Try all 4 neighboring cells
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==word[idx] && !vis[nr][nc]){
                if(dfs(nr,nc,board,vis,n,m,word,idx+1)) return true;
            }
        }
        // Backtrack -> Current path failed. Unmark this cell so it can be used in another path.
        vis[r][c]=0;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size(),idx=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[idx]){
                    if(dfs(i,j,board,vis,n,m,word,idx+1)) return true;
                }
            }
        }
        return false;
    }
};

// Visited in DFS + Backtracking
// If the problem says:
// The same cell/node cannot be used more than once in the current path
// we use visited or a special marker like '#'.
// vis[r][c] = true;
// This means:
// "I am currently using this cell in this path, so I cannot use it again in this same path."
// After exploring this path, we undo it:
// vis[r][c] = false;
// Why do we unmark?
// Because the restriction is only for the current path.
// The same cell can be used in a different path.
// Path 1: A → B → C ✓ 
// Path 1 fails 
// Backtrack: A, B, C become available again 
// Path 2: D → B → E ✓
// So remember:
// Mark → Explore → Unmark
// The cell is unavailable during the current path, but available for another path.
// Why is this called backtracking?
// Because we:
// Take a choice.
// Explore from that choice.
// If it doesn't work, go back.
// Undo the choice.
// Try another choice.
// Choose → Mark → DFS → Fails → Undo → Try another path
// Why don't we always do this in normal DFS?
// In normal graph DFS, visited usually means:
// "I have already processed this node, so I don't need to process it again."
// Once we visit a node:
// vis[node] = true;
// we normally keep it true.
// We don't do:
// vis[node] = false;
// because we're not trying to find and compare every possible path. We're simply traversing the graph and avoiding cycles/repeated processing.
// Example:
// A → B → C ↓ D
// If normal DFS has already visited B, there is usually no reason to visit B again from another route.
// So:
// Normal DFS: visit → mark permanently
// Whereas:
// Backtracking: choose → mark → explore → unmark → try another choice
// The key difference
// Normal DFS:
// "Have I ever visited this node?"
// Backtracking:
// "Have I visited this cell/node in my CURRENT path?"
// That one difference is extremely important.
// Future reference
// Whenever you see:
// "same cell cannot be used twice"
// "same element cannot be chosen twice in the current combination/path"
// "try all possible paths"
// "choose → explore → undo"
// think:
// DFS + Backtracking → Mark → Explore → Unmark
// But don't automatically unmark in every DFS.
// Unmark only when the visited state represents the current path rather than permanently processed nodes.