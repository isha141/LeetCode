class Solution {
public:
    string getHint(string s, string g) {
        int n=s.size(); 
        int c=0; 
        int res=0;
        map<char,int>mp;
        for(auto itr: s)
            mp[itr]++;
        for(int i=0;i<n;++i){
            if(s[i]==g[i]){
                c++;
                mp[s[i]]--;
                s[i]='&';
            }
        }
        for(int i=0;i<n;++i){
            if(s[i]!='&'){
                if(mp[g[i]]>0){
                    res++; 
                mp[g[i]]--;
                }
            }
        }
        string ans="";
        ans+=to_string(c);
        ans+='A';
        ans+=to_string(res);
        ans+='B';
        return ans;
    }
};