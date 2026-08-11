class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        unordered_set<int> hashSet;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int third=-(nums[i]+nums[j]);
                if(hashSet.find(third)!=hashSet.end()){
                    st.insert({nums[i],nums[j],third});
                }
            }
            hashSet.insert(nums[i]);
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};