class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt=0;
        unordered_map<char,int> mpp;
        for(auto it:allowed) mpp[it]++;
        for(auto it:words){
            bool flag=false;
            for(auto jt:it){
                if(!mpp.count(jt)) flag=true;
            }
            if(!flag) cnt++;
        }
        return cnt;
    }
};