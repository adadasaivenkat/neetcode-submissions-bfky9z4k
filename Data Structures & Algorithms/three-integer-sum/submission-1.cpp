class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int first=nums[i],j=i+1,k=n-1;
            while(j<k){
                int second=nums[j],third=nums[k];
                int sum=first+second+third;
                if(sum==0){
                    res.push_back({first,second,third});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum<0){
                    j++;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
                else if(sum>0){
                    k--;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return res;
    }
};

// Ex-1
// -4 -1 -1 0 1 2 

// 1st iteration
// -4 -1 2 = -3
// -4 0 2 = -2
// -4 1 2 = -1

// 2nd iteration
// -1 -1 2 = 0
// -1 0 1 = 0

// Ex-2
// index:  0   1   2   3   4   5   6   7   8   9   10  11  12
// value: -2  -2  -2  -1  -1  -1   0   0   0   2   2   2   2