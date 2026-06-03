class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        for(auto it:s){
            if(it==']'){
                string temp;
                while(!stk.empty() && stk.top()!='['){
                    temp+=stk.top();
                    stk.pop();
                }
                stk.pop();
                string digits;
                while(!stk.empty() && isdigit(stk.top())){
                    digits+=stk.top();
                    stk.pop();
                }
                reverse(digits.begin(),digits.end());
                reverse(temp.begin(),temp.end());
                int num=stoi(digits);
                // Expanded
                string exp;
                for(int i=0; i<num; i++){
                    exp+=temp;
                }
                for(int i=0; i<exp.size(); i++) stk.push(exp[i]);
            }
            else stk.push(it);
        }
        string res;
        while(!stk.empty()){
            res+=stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};