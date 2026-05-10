class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        vector<pair<int,int>> temp;
        for(auto it:mpp) temp.push_back({it.second,it.first});
        sort(temp.rbegin(),temp.rend());   // Reverse sort => rbegin() and rend()
        vector<int> res;
        for(int i=0; i<k; i++){
            res.push_back(temp[i].second);
        }
        return res;
    }
};
