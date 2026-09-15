class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_map<string,int> mpp;
        for(auto &e:emails){
            string temp;
            int dIdx=-1;
            for(int i=0; i<e.size(); i++){
                if(e[i]=='.') continue;
                else if(e[i]=='+'){
                    while(e[i]!='@') i++;
                    dIdx=i;
                    break;
                }
                else if(e[i]=='@'){
                    dIdx=i;
                    break;
                }
                else temp+=e[i];
            }
            for(int i=dIdx; i<e.size(); i++) temp+=e[i];
            mpp[temp]++;
        }
        return mpp.size();
    }
};