class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(!st.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        if(st.count(beginWord)) st.erase(beginWord);
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
                        if(st.count(word)){
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