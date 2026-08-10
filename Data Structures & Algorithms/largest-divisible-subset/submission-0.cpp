class Solution {
private:
    bool isValid(vector<int>& arr){
        int n=arr.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]%arr[j]!=0 && arr[j]%arr[i]!=0) return false;
            }
        }
        return true;
    }
    void solve(int idx, int n, vector<int>& nums, vector<int>& temp, vector<int> &res){
        if(idx==n){
            if(isValid(temp) && temp.size()>res.size()){
                res=temp;
            }
            return;
        }
        // Take
        temp.push_back(nums[idx]);
        solve(idx+1,n,nums,temp,res);
        // Not Take
        temp.pop_back();
        solve(idx+1,n,nums,temp,res);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> temp,res;
        int n=nums.size();
        solve(0,n,nums,temp,res);
        return res;
    }
};