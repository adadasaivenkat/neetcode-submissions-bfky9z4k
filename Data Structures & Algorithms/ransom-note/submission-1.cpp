class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp1,mpp2;
        for(auto it:ransomNote) mpp1[it]++;
        for(auto it:magazine) mpp2[it]++;
        for(auto it:ransomNote){
            if(mpp1[it]>mpp2[it]) return false;
        }
        return true;
    }
};