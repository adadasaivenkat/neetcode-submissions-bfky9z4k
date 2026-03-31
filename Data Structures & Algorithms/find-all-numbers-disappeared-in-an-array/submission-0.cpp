class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=1; i<=n; i++) st.insert(i);
        for(auto it:nums){
            if(st.count(it)) st.erase(it);
        }
        vector<int> res;
        for(auto it:st) res.push_back(it);
        return res;
    }
};