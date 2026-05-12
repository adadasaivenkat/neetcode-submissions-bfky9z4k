class Solution {
private:
    void fun(int idx, vector<int>& nums, int n, 
    vector<int> temp, vector<vector<int>> &res){
        if(idx==n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        fun(idx+1,nums,n,temp,res);
        temp.pop_back();
        fun(idx+1,nums,n,temp,res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        fun(0,nums,nums.size(),temp,res);
        return res;
    }
};
