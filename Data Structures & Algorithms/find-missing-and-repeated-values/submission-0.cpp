class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int> mpp;
        vector<int> ele;
        for(auto it:grid){
            for(auto jt:it){
                mpp[jt]++;
                ele.push_back(jt);
            }
        }
        int n=grid.size()*grid.size();
        int rep=0;
        for(auto it:mpp){
            if(it.second==2){
                rep=it.first;
                break;
            }
        }
        int xorr=rep;
        for(auto it:ele) xorr^=it;
        for(int i=1; i<=n; i++) xorr^=i;
        return {rep,xorr};
    }
};