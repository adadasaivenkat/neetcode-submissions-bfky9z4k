class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res=nums;
        for(auto it:nums) res.push_back(it);
        return res;
    }
};