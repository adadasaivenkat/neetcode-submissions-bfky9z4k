class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mpp;
        for(auto &a:arr1) mpp[a]++;
        vector<int> res;
        for(auto &a:arr2){
            while(mpp[a]>0){
                res.push_back(a);
                mpp[a]--;
            }
            if(mpp[a]==0) mpp.erase(a);
        }
        for(auto &it:mpp){
            while(it.second>0){
                res.push_back(it.first);
                it.second--;
            }
        }
        return res;
    }
};