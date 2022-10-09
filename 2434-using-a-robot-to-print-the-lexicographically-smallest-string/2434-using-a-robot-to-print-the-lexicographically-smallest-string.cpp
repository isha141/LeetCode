class Solution {
    int low(vector<int>&freq)
    {
        for(int i=0;i<26;++i){
            if(freq[i]!=0){
                return 'a'+i;
            }
        }
        return 'a';
    }
public:
    string robotWithString(string s) {
        int n=s.size();
        stack<char>st;
        string ans="";
        vector<int>freq(26,0);
        for(auto itr: s)
            freq[itr-'a']++;
        for(auto it: s){
            st.push(it);
            freq[it-'a']--;
            while(!st.empty() && st.top()<=low(freq)){
                ans+=st.top();
                st.pop();
            }
        } 
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};