class Solution{	
	public:		
		vector<int> singleNumber(vector<int>& nums){
            unordered_map<int,int> mpp;
            for(auto it:nums) mpp[it]++;
            vector<int> res;
            for(auto it:nums){
                if(mpp[it]==1) res.push_back(it);
            }
            sort(res.begin(),res.end());
            return res;
		}
};