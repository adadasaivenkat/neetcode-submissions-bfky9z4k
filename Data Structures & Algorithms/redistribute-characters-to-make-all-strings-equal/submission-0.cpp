class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char,int> mpp;
        for(auto it:words){
            for(auto jt:it) mpp[jt]++;
        }
        for(auto it:mpp){
            if(it.second % words.size()!=0) return false;
        }
        return true;
    }
};