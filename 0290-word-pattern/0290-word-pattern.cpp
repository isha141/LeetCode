class Solution {
public:
    bool wordPattern(string pat, string s) {
        int n=pat.size();
        stringstream ss(s);
        string word;
        int k=0;
        map<char,string>mp;
        set<string>st;
        while(ss>>word){
            if(mp.find(pat[k])==mp.end() && st.find(word)==st.end()){
                mp[pat[k]]=word;
                st.insert(word);
            }
            else if(mp[pat[k]]!=word)
                return 0;
            k++;
        }
        if(k>=n)
        return 1;
        return 0;
    }
};