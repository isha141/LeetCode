class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int count=0;
        for(auto itr: s){
            if(itr==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                   count+=1;
                }
            }
            else{
                st.push(itr);
            }
        }
         return count+st.size();
    }
};