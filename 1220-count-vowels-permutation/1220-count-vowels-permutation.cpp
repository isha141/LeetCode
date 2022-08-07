
class Solution { 
    private: 
    const int mod=1e9+7;
    int solve(int n,map<char,vector<char>>&mp,char ch,unordered_map<char,vector<int>>&dp)
    {
        if(n==0)
            return 1;
        int ans=0; 
        if(dp[ch][n]) return dp[ch][n];
        for(auto c : mp[ch])
          dp[ch][n]=(dp[ch][n]+solve(n-1,mp,c,dp))%mod;
        return dp[ch][n];
    }
public:
    int countVowelPermutation(int n) {
        map<char,vector<char>>mp; 
        char c='s'; 
        unordered_map<char,vector<int>>dp; 
        dp['s']=dp['a']=dp['e']=dp['i']=dp['o']=dp['u']=vector<int>(n+1);
        mp['s']={'a','e','i','o','u'};
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        return solve(n,mp,'s',dp);
    }
};