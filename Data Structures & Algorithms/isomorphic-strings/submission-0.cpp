class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        unordered_map<char,char> m1,m2;
        int size=s.size(); // int size=t.size();
        for(int i=0; i<size; i++){
            if((m1.count(s[i]) && m1[s[i]]!=t[i])
            || (m2.count(t[i]) && m2[t[i]]!=s[i])){
                return false;
            }
            else{  
                m1[s[i]]=t[i];
                m2[t[i]]=s[i];
            }
        }
        return true;
    }
};