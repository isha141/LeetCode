class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mapp) {
        int n=mapp.size();
        map<char,unordered_set<char>>mp;
        for(auto it: mapp){
            mp[it[0]].insert(it[1]);
        } 
        for(int i=0;i+sub.size()<=s.size();++i){ 
            // cout<<i<<" "; 
            int j=0;
            for( j=0;j<sub.size();++j){
                if(s[i+j]!=sub[j] && mp[sub[j]].count(s[i+j])==0)
                    break;
            }
            if(j==sub.size())
                    return 1;
        }
        return 0;
    }
};