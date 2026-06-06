class Solution {
private:
    void reverse(vector<int> &v){
        int l=0,r=v.size()-1;
        while(l<r){
            int temp=v[l];
            v[l]=v[r];
            v[r]=temp;
            l++;
            r--;
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<m; j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        for(auto &it:matrix){
            reverse(it);
        }
    }
};