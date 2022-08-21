class Solution {
public:
    string decodeString(string s) {
        int prevn=0;
        string prev="";
        int currn=0;
        string curr="";
        stack<string>st; 
        for(auto itr: s){
            if(itr=='['){
                st.push(curr);
                st.push(to_string(currn));
                curr="";
                currn=0;
            }
            else if(itr==']'){
             string prevt=st.top();
                st.pop();  
                prevn=0;
                for(auto itr: prevt){
                    prevn=prevn*10+itr-'0';
                } 
                // cout<<prevn<<" ";
                prev=st.top();
                st.pop();
                string t="";
                for(int i=0;i<prevn;++i)
                    t+=curr;
                prev+=t;
                curr=prev;
                currn=0;
            }
            else if(isdigit(itr)){
                currn=currn*10+(itr-'0');
            }
            else 
                curr+=itr;
        }
    return curr;
    }
};