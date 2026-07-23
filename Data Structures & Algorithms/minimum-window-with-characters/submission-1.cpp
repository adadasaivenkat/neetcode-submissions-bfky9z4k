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
        int l=0,r=0,n=s.size(),minLen=INT_MAX,start=-1,end=-1;
        unordered_map<char,int> mpp1,mpp2;
        for(auto &it:t) mpp1[it]++;
        while(r<n){
            if(t.find(s[r])!=string::npos) mpp2[s[r]]++;
            while(check(mpp1,mpp2,t)){
                if((r-l+1)<minLen){
                    minLen=r-l+1;
                    start=l;
                    end=r;
                }
                if(mpp2.find(s[l])!=mpp2.end()) mpp2[s[l]]--;
                if(mpp2[s[l]]==0) mpp2.erase(s[l]);
                l++;
            }
            r++;
        }
        if(start==-1 && end==-1) return "";
        else{
            string res;
            for(int i=start; i<=end; i++) res+=s[i];
            return res;
        }
    }
};

// Sliding Window
// Time Complexity = O(n * m)
// Space Complexity = O(m)
// 1. mpp1 stores frequencies of characters from t:
//    O(m)
// 2. mpp2 stores frequencies of characters in the window:
//    O(m), because only characters found in t are added.
// TOTAL SPACE:
// O(m + m) = O(2m) = O(m)