class Solution {
private:
    void reverse(vector<int> &v){
        int l=0,r=v.size()-1;
        while(l<r){
            swap(v[l],v[r]);
            l++;
            r--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(auto &it:matrix){
            reverse(it);
        }
    }
};