class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string temp="";
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            }
            else temp+=s[i];
        }
        v.push_back(temp);
        if(pattern.size()!=v.size()) return false;
        unordered_map<char,string> mpp1;
        unordered_map<string,char> mpp2;
        int n=pattern.size(); // int n=v.size();
        for(int i=0; i<n; i++){
            if(mpp1.count(pattern[i]) || mpp2.count(v[i])){
                if(mpp1[pattern[i]]!=v[i] || mpp2[v[i]]!=pattern[i]) return false;
            }
            mpp1[pattern[i]]=v[i];
            mpp2[v[i]]=pattern[i];
        }
        return true;
    }
};