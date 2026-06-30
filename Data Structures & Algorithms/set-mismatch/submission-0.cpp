class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        int dup,xorr=0,cnt=0;
        for(auto it:mpp){
            if(it.second==2){
                dup=it.first;
                break;
            }
        }
        for(int i=1; i<=nums.size(); i++) xorr^=i;
        for(auto it:nums){
            if(it==dup && cnt==0){
                xorr^=it;
                cnt++;
            }
            xorr^=it;
        }
        return {dup,xorr};
    }
};