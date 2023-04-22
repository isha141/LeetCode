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
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=solve(n-1,n-1,s,temp,dp); 
        return n-ans;
    }
};