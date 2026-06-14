class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0; i<n; i++){
            /*
            for(int j=i+1; j<m; j++){
                // For Square matrix Eg... 2×2, 3×3, 4×4
                swap(matrix[i][j],matrix[j][i]);
            }
            */
            for(int j=0; j<m; j++){
                // For Non Square matrix Eg... 2×3, 3×2, 4×3
                res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
};