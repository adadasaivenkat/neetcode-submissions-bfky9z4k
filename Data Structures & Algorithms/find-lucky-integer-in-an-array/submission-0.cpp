class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto it:arr) mpp[it]++;
        sort(arr.begin(),arr.end(),greater<int>());
        for(auto it:arr){
            if(mpp[it]==it) return it;
        }
        return -1;
    }
};