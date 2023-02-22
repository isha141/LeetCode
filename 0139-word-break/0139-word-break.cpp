class Solution { 
    private: 
    int n;
     map<string,int>mp;
    bool solve(int i,string &s,vector<int>&dp){
        if(i>=n)
             return 1; 
        if(dp[i]!=-1) 
            return dp[i];
        string temp="";
        for(int j=i;j<n;++j){
            temp+=s[j];
            if(mp.find(temp)!=mp.end()){
                if(solve(j+1,s,dp)){
                    dp[i]=1;
                    return dp[i];
                }
                    
            }
        }
        return dp[i]=0;
    }
public:
    bool wordBreak(string s, vector<string>& word) { 
        n=s.size();
        for(auto itr: word){
            mp[itr]++;
        } 
        vector<int>dp(n,-1);
        return  solve(0,s,dp);
    }
};