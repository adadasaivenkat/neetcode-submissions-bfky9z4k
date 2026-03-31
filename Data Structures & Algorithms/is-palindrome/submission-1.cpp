class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(auto it:s){
            if(isalnum(it)){
                temp+=tolower(it);
            }
        }
        string rev=temp;
        reverse(rev.begin(),rev.end());
        return rev==temp;
    }
};
