class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        int size=min(first.size(),last.size());
        string res="";
        for(int i=0; i<size; i++){
            if(first[i]==last[i]) res+=first[i];  // res=last[i];
            else if(first[i]!=last[i]) break;
        }
        return res;
    }
};