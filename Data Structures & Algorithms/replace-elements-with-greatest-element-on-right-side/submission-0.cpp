class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> res(arr.size());
        for(int i=0; i<arr.size(); i++){
            int rightMax=-1;
            for(int j=i+1; j<arr.size(); j++){
                rightMax=max(rightMax,arr[j]);
            }
            res[i]=rightMax;
        }
        return res;
    }
};