class Solution { 
    private:
    int n;
    int solve(int i,int j,string &s,string &temp,vector<vector<int>>&dp){
        // if(i<0 && j<0) return 0;
        if(i<0) 
             return 0;
        if(j<0) return 0;
        if(dp[i][j]!=-1)
             return dp[i][j];
        int take=0;
        int not_take=0;
        if(s[i]==temp[j]){
            take=1+solve(i-1,j-1,s,temp,dp);
        }
        else {
            not_take=max(solve(i-1,j,s,temp,dp),solve(i,j-1,s,temp,dp));
        }
        return dp[i][j]=max(take,not_take);
    }
public:
    int minInsertions(string s) {
        string temp=s;
        reverse(temp.begin(),temp.end());
        n=s.size(); 
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){ 
                int take=0;
                int not_take=0;
                if(s[i-1]==temp[j-1]){
                    take=1+dp[i-1][j-1];
                }
                else{
                    not_take=max(dp[i][j-1],dp[i-1][j]);
                }
                ans=max(ans,max(take,not_take));
                dp[i][j]=max(take,not_take);
            }
        }
        // int ans=solve(n-1,n-1,s,temp,dp);  
        // int ans=dp[n-1][n-1];
        return n-ans;
    }
};