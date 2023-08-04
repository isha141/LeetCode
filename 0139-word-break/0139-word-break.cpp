int dp[301];
class Solution {
    private: 
    int n;
    int solve(int i,string &s,map<string,int>&mp){
        if(i>=n)
              return 1;
        if(dp[i]!=-1)
              return dp[i];
        string temp=""; 
        int ans=0;
        for(int j=i;j<n;++j){
            temp+=s[j];
            if(mp.find(temp)!=mp.end()){
              ans=ans|solve(j+1,s,mp);
            }
        }
        return dp[i]=ans;
    }
public:
    bool wordBreak(string s, vector<string>& word) { 
        map<string,int>mp;
        n=s.size();
         for(auto it: word){
             mp[it]++;
         } 
        memset(dp,-1,sizeof(dp));
        return solve(0,s,mp);
    }
};