class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int,string> mpp;
        for(int i=0; i<names.size(); i++) mpp[heights[i]]=names[i];
        sort(heights.rbegin(),heights.rend());
        vector<string> res;
        for(auto it:heights) res.push_back(mpp[it]);
        return res;
    }
};