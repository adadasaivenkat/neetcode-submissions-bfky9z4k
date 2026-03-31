class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(auto it:arr) mpp[it]++;
        int res=-1;
        for(auto it:arr){
            if(mpp[it]==it) res=max(it,res);
        }
        return res;
    }
};