class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<int,int> mpp1;
        unordered_map<int,int> mpp2;
        int n=s.size(); // int n=t.size();   Becoz both sizes are equal.
        for(int i=0; i<n; i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        return mpp1==mpp2;
    }
};
