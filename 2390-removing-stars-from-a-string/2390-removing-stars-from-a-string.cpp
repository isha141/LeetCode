class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(int i=0;i<s.size();++i){
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
           int count=0;
            while(st.size() && st.top()=='*'){
                st.pop();
                count++;
            }
            while( st.size() && count>0){ 
                if(st.top()=='*'){
                st.pop();  
                    count+=2;
                }
                else 
                    st.pop();
                count-=1;
            }
            if(st.size() && st.top()!='*'){
                ans+=st.top();
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};