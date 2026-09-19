class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(auto &n:nums) st.insert(n);
        vector<int> temp(st.begin(),st.end());
        nums=temp;
        return st.size();
    }
};