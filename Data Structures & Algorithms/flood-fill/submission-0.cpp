class Solution {
private:
    void dfs(vector<vector<int>>& image, vector<vector<int>>& newImage, 
    int sr, int sc, int color, int initialCol, int dr[], int dc[], int n, int m){
        newImage[sr][sc]=color;
        for(int i=0; i<4; i++){
            int nr=sr+dr[i];
            int nc=sc+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && 
            image[nr][nc]==initialCol && newImage[nr][nc]!=color){
                dfs(image,newImage,nr,nc,color,initialCol,dr,dc,n,m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialCol=image[sr][sc];
        if(initialCol==color) return image;
        vector<vector<int>> newImage=image;
        int n=image.size(),m=image[0].size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        dfs(image,newImage,sr,sc,color,initialCol,dr,dc,n,m);
        return newImage;
    }
};