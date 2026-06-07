class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        if(st.find(beginWord)!=st.end()) st.erase(beginWord);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            level++;
            for(int i=0; i<size; i++){
                string word=q.front();
                q.pop();
                if(word==endWord) return level;
                for(int i=0; i<word.size(); i++){
                    char original=word[i];
                    for(char ch='a'; ch<='z'; ch++){
                        word[i]=ch;
                        if(st.find(word)!=st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i]=original;
                }
            }
        }
        return 0;
    }
};