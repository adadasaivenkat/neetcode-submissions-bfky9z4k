class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mpp;
        for(auto it:arr){
            mpp[it]++;
        }
        vector<string> res;
        for(auto it:arr){
            if(mpp[it]==1) res.push_back(it);
        }
        if(res.size()<k) return "";
        else return res[k-1];
    }
};