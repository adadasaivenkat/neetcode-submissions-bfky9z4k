class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mpp;
        for(int i=0; i<nums2.size(); i++){
            bool flag=false;
            for(int j=i+1; j<nums2.size(); j++){
                if(nums2[j]>nums2[i]){
                    flag=true;
                    mpp[nums2[i]]=nums2[j];
                    break;
                }
            }
            if(!flag) mpp[nums2[i]]=-1;
        }
        vector<int> ans;
        for(auto it:nums1){
            ans.push_back(mpp[it]);
        }
        return ans;
    }
};