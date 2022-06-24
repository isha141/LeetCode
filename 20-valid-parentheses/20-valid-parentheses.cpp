class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
        for(auto itr: s){
            if(itr=='(')
                st.push(itr);
            else if(itr=='{')
                st.push(itr);
          else  if(itr=='[')
              st.push(itr);
            else{ 
                if(st.empty()) return 0;
                if(itr==')')
                {
                   if(st.top()!='(')
                       return 0; 
                    st.pop();
                }
              else if(itr=='}'){
                      if(st.top()!='{')
                          return 0;
                      st.pop();
                  } 
                else if(itr==']'){
                    if(st.top()!='[')
                        return 0;
                    st.pop();
                }
              }
        }
        return st.empty();
    }
};