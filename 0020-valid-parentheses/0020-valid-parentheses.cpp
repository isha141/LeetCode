class Solution {
public:
    bool isValid(string str) {
        stack<char>s;
        for(auto itr: str){
            if(itr=='(' || itr=='[' || itr=='{'){
                s.push(itr);
            }
            else{ 
                if(s.size()==0) return 0;
                if(itr=='}' && s.top()=='{'){
                    s.pop();
                }
                else if(itr==']' && s.top()=='['){
                    s.pop();
                }
                else if(itr==')' && s.top()=='('){
                    s.pop();
                }
                else
                    return 0;
            }
        }
        if(s.size()) return 0;
        return 1;
    }
};