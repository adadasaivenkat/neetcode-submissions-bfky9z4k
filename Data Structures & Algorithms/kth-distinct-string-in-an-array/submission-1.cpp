class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        for(auto it:arr) mpp[it]++;
        vector<string> temp;
        for(auto it:arr){
            if(mpp[it]==1) temp.push_back(it);
        }
        return temp.size()<k ? "" : temp[k-1];
    }
};