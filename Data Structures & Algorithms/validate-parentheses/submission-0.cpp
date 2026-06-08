class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                stk.push(it);
            }
            else if(it==')'){
                if(stk.empty() || stk.top()!='(') return false;
                else stk.pop();
            }
            else if(it=='}'){
                if(stk.empty() || stk.top()!='{') return false;
                else stk.pop();
            }
            else if(it==']'){
                if(stk.empty() || stk.top()!='[') return false;
                else stk.pop();
            }
        }
        return stk.empty();
    }
};
