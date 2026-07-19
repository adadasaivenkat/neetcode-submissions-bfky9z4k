class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pref(n+1,0);
        string vowels="aeiouAEIOU";
        for(int i=1; i<=n; i++){
            pref[i]=pref[i-1];
            string word=words[i-1];
            if(vowels.find(word[0])!=string::npos && vowels.find(word[word.size()-1])!=string::npos){
                pref[i]+=1;
            }
        }
        vector<int> res;
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            l++;
            r++;
            res.push_back(pref[r]-pref[l-1]);
        }
        return res;
    }
};