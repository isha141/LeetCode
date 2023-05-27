class Solution {
    private:
    int n;
    map<string,int>mp;
    int solve(int i,string &s,vector<int>&dp){
        if(i>=n)
            return 0;
        if(dp[i]!=-1) 
            return dp[i];
        int ans=1+solve(i+1,s,dp); 
        string temp="";
        for(int j=i;j<n;++j){
            temp+=s[j];
            if(mp.find(temp)!=mp.end())
                ans=min(ans,solve(j+1,s,dp));
        }
        return dp[i]=ans;
    }
public:
    int minExtraChar(string s, vector<string>& dic) {
        for(auto itr:dic)
            mp[itr]++;
        n=s.size(); 
        vector<int>dp(55,-1);
        return solve(0,s,dp);
    }
};
