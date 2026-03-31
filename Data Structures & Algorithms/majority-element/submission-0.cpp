class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size()/2;
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        for(auto it:mpp){
            if(it.second>size) return it.first;
        }
    }
};