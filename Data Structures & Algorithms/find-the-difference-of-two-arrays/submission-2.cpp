class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res1,res2;
        unordered_set<int> st1(nums1.begin(),nums1.end()),st2(nums2.begin(),nums2.end());
        for(auto &n:st1){
            if(st2.find(n)==st2.end()) res1.push_back(n);
        }
        for(auto &n:st2){
            if(st1.find(n)==st1.end()) res2.push_back(n);
        }
        return {res1,res2};
    }
};