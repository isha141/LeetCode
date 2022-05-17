class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto itr: s)
        {
            if(itr=='('|| itr=='{'|| itr=='[')
                st.push(itr);
            else if(itr==']')
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
            else if(itr=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop(); 
                else
                    return false;
            }
            else if(itr==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};