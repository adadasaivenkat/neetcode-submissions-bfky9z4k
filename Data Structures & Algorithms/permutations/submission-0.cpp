class Solution {
private:
    void fun(int n, vector<int>& nums, vector<int>& temp, vector<int>& used, vector<vector<int>> &res){
        if(temp.size()==n){
            res.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i]==1) continue;
            used[i]=1;
            temp.push_back(nums[i]);
            fun(n,nums,temp,used,res);
            used[i]=0;
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> used(n,0);
        fun(n,nums,temp,used,res);
        return res;
    }
};
