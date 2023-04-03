int dp[1007];
class Solution { 
    private:
     map<string,int>mp; 
    bool solve(int i,string &s){
        if(i>=s.size())
             return 1;  
        if(dp[i]!=-1)
            return dp[i]; 
        // cout<<i<<" "<<s.substr(i)<<endl;
        string temp="";
        for(int k=i;k<s.size();++k){
             temp+=s[k];
            if(mp.find(temp)!=mp.end()){
                dp[i]=1;
                if(solve(k+1,s))    
                return 1;
            }
        }
        return dp[i]=0;
        // return 0;
    }
public:
    bool wordBreak(string s, vector<string>& word) {
        // map<string,int>mp;  
        memset(dp,-1,sizeof(dp));
        for(auto itr: word)
            mp[itr]++;
        return solve(0,s);
    }
};