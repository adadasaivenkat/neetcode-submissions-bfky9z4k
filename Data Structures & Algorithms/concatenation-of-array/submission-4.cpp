class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> newArr(nums.begin(),nums.end());
        for(auto it:nums) newArr.push_back(it);
        return newArr;
    }
};