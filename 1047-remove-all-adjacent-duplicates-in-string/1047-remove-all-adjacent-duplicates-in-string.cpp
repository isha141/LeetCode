class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.size();++i){
             // st.push(s[i]); 
            bool flag=0;
            while(st.size() && st.top()==s[i]){
                st.pop();
                flag=1;
            }
            if(!flag)
                st.push(s[i]);
            
        } 
        string ans="";
        while(!st.empty()){
            ans+=st.top();
        st.pop();
        }
          reverse(ans.begin(),ans.end());
    return ans;
    }
};