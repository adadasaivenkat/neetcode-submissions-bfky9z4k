class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt=0;
        for(auto it:details){
            int num=stoi(it.substr(11,2));
            if(num>60) cnt++;
        }
        return cnt;
    }
};