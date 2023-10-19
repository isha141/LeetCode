class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>a;
        for(auto it: s){
            if(it=='#'){
                if(a.size())
                    a.pop();
            }
            else
            a.push(it);
        }
        string ans="";
        while(!a.empty()){
            ans+=a.top();
             a.pop();
        }
        for(auto it: t){
            if(it=='#'){
                if(a.size())
                    a.pop();
            }
            else
            a.push(it);
        }
         string ans2="";
        while(!a.empty()){
            ans2+=a.top();
            a.pop();
        }
        return (ans==ans2);
    }
};