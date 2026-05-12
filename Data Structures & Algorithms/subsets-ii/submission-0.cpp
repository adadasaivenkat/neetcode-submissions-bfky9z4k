class Solution {
private:
    void fun(int idx, vector<int>& nums, int n, 
    vector<int> temp, set<vector<int>> &res){
        if(idx==n){
            res.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        fun(idx+1,nums,n,temp,res);
        temp.pop_back();
        fun(idx+1,nums,n,temp,res);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> res;
        vector<int> temp;
        fun(0,nums,nums.size(),temp,res);
        vector<vector<int>> ans;
        for(auto it:res) ans.push_back(it);
        return ans;
    }
};