class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,n=s.size(),cnt=0,minLen=INT_MAX,start=-1,end=-1;
        unordered_map<char,int> mpp;
        for(auto &it:t) mpp[it]++;
        while(r<n){
            if(mpp[s[r]]>0) cnt++;
            mpp[s[r]]--;
            while(cnt==t.size()){
                if((r-l+1)<minLen){
                    minLen=r-l+1;
                    start=l;
                    end=r;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) cnt--;
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

// Time Complexity: O(N + M)
// M -> Traverse t once to build the frequency map.
// N -> Both l and r pointers move only forward through s.
// Although there is a nested while loop, l moves at most N times in total,
// not N times for every r. Hence, sliding window takes O(N), not O(N^2).
// If a pointer moved forward and then repeatedly backward/restarted for each iteration,
// it could lead to O(N^2). Here, total pointer movements are at most 2N -> O(N).
// Overall TC = O(N + M).
// Space Complexity: O(M)
// Frequency map stores characters from t.
// For a fixed character set (e.g., ASCII), space can be considered O(1).