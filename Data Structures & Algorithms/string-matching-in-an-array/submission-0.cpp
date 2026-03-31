class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(auto it:words){
            for(auto jt:words){
                if(it!=jt && jt.find(it)!=string::npos){
                    res.push_back(it);
                    break;
                }
            }
        }
        return res;
    }
};