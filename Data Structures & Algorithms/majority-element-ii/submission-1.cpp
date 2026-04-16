class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        vector<int> res;
        int size=nums.size()/3;
        for(auto it:mpp){
            if(it.second>size) res.push_back(it.first);
        }
        return res;
    }
};