class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        string ans="";
        vector<int>last(26,0);
        for(int i=0;i<n;++i){
            last[s[i]-'a']=i;
        } 
        vector<bool>seen(26,0);
        stack<char>st;
        for(int i=0;i<n;++i){
            if(seen[s[i]-'a'])
                continue;
            while(!st.empty() && st.top()>s[i] && last[st.top()-'a']>i){
                char ch=st.top(); 
                st.pop();
                seen[ch-'a']=0;
            }
            st.push(s[i]);
            seen[s[i]-'a']=1;
        }
        while(!st.empty()){
            auto itr=st.top(); 
            st.pop();
            ans+=itr;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};