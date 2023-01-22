class Solution {
    map<string,int>mp; 
    int n;
    bool solve(string s,vector<string>& word){
        if(find(word.begin(),word.end(),s)!=word.end())
            return 1;  
        if(mp.find(s)!=mp.end())
            return mp[s];
        for(int i=1;i<n;++i){
            string a=s.substr(0,i);
            if(find(word.begin(),word.end(),a)!=word.end() && solve(s.substr(i),word)){
                mp[a]=1;
                return 1;
            }
        }
         mp[s]=0; 
        return 0;
    }
public:
    bool wordBreak(string s, vector<string>& word) {
        n=s.size();
        return solve(s,word);
    }
};