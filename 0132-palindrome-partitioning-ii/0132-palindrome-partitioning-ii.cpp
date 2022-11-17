class Solution { 
    private: 
    bool ispalin(string &temp){
        int i=0;
        int n=temp.size();
        while(i<n/2){
            if(temp[i]!=temp[n-i-1])
                return 0;
            i++;
        }
        return 1;
    }
    int n;
    int solve(int i,string &s,vector<int>&dp){
         if(i>=n)
             return 0;
        int ans=1e9;
        int c=0; 
        if(dp[i]!=-1)
            return dp[i];
        string temp="";
        for(int j=i;j<s.size();++j){
            temp+=s[j];
            if(ispalin(temp)){
            c=1+(solve(j+1,s,dp));
                ans=min(ans,c);
            }
        }
        return dp[i]=ans;
    }
public:
    int minCut(string s) {
         n=s.size(); 
          string temp=""; 
        vector<int>dp(n,-1);
        return solve(0,s,dp)-1;
    }
};