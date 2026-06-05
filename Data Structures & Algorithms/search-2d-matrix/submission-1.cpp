class Solution{
private:
    bool binarySearch(vector<int> &v, int target){
        int l=0,h=v.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(v[mid]==target) return true;
            else if(target<v[mid]) h=mid-1;
            else l=mid+1;
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        int n=mat.size(),m=mat[0].size();
        for(int i=0; i<n; i++){
            if(mat[i][0]<=target && target<=mat[i][m-1]){
                return binarySearch(mat[i],target);
            }
        }
        return false;
    }
};