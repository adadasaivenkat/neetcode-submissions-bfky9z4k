class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        for(auto it:nums1) mpp[it]++;
        vector<int> res;
        unordered_set<int> st(nums2.begin(),nums2.end());
        for(auto it:st){
            if(mpp.count(it)) res.push_back(it);
        }
        return res;
    }
};