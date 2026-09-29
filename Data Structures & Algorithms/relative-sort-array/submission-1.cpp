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

// for(auto &it:mpp){
//     ...
//     if(it.second==0) mpp.erase(it.first);
// }
// You cannot erase an element from a map while using a range-based for loop over that same map. This invalidates the iterator and can cause undefined behavior.