class Solution {
private:
    bool check(unordered_map<char,int> &mpp1, unordered_map<char,int> &mpp2, string &t){
        for(int i=0; i<t.size(); i++){
            // mpp2[t[i]]>=mpp1[t[i]] => true (All required frequencies are satisfied)
            if(mpp2[t[i]]<mpp1[t[i]]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n=s.size(),minLen=INT_MAX,start=-1,end=-1;
        unordered_map<char,int> mpp1;
        for(auto &it:t) mpp1[it]++;
        for(int i=0; i<n; i++){
            unordered_map<char,int> mpp2;
            for(int j=i; j<n; j++){
                mpp2[s[j]]++;
                if(check(mpp1,mpp2,t)){
                    if((j-i+1)<minLen){
                        minLen=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        if(start==-1 && end==-1) return "";
        else{
            string res;
            for(int i=start; i<=end; i++) res+=s[i];
            return res;
        }
    }
};

// Time Complexity = O(n^2 * m)
// mpp1 stores frequencies of characters from t:
// O(m)
// mpp2 stores frequencies of characters in the current substring:
// O(n) in the worst case.
// Space Complexity = O(n + m)
// NOTE:
// If we consider a fixed character set (e.g. ASCII),
// both frequency maps have bounded size, so auxiliary
// map space can be considered O(1).
// If output string space is not counted:
// Auxiliary Space = O(1) for a fixed character set.