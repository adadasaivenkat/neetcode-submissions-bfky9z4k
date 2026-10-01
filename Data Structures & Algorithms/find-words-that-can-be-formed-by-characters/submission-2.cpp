class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> mpp1;
        int len=0;
        for(auto &ch:chars) mpp1[ch]++;
        for(auto &w:words){
            unordered_map<char,int> mpp2;
            for(auto &ch:w) mpp2[ch]++;
            bool flag=true;
            for(auto &ch:w){
                if(mpp1[ch]>=mpp2[ch]) continue;
                else{
                    flag=false;
                    break;
                }
            }
            if(flag) len+=w.size();
        }
        return len;
    }
};