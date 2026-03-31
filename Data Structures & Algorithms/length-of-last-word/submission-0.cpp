class Solution {
public:
    int lengthOfLastWord(string s) {
        vector<string> v;
        string temp="";
        for(auto it:s){
            if(it==' '){
                if(temp!=""){
                    v.push_back(temp);
                    temp="";
                }
            }
            else temp+=it;
        }
        if(temp!="") v.push_back(temp);
        return v[v.size()-1].size();
    }
};