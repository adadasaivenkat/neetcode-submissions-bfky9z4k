class Solution {
public:
    int scoreOfString(string s) {
        vector<int> v;
        for(auto it:s) v.push_back(int(it));
        int sum=0;
        for(int i=1; i<v.size(); i++){
            sum+=abs(v[i]-v[i-1]);
        }
        return sum;
    }
};