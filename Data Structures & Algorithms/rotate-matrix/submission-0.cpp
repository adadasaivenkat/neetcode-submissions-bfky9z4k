class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> transpose(n,vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                transpose[j][i]=matrix[i][j];
            }
        }
        for(auto &it:transpose) reverse(it.begin(),it.end());
        matrix=transpose;
    }
};