class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mpp;
        int len=0;
        for(auto it:chars) mpp[it]++;
        for(auto it:words){
            unordered_map<char,int> mpp2;
            bool flag=true;
            for(auto jt:it) mpp2[jt]++;
            for(auto kt:it){
                if(mpp[kt]<mpp2[kt]){     // True When mpp[kt]>=mpp2[kt]
                    flag=false;
                    break;
                }
            }
            if(flag){
                len+=it.size();
            }
        }
        return len;
    }
};