int dp[1003][1003];
class Solution { 
    private:
    int n;
    int solve(int i,int j,string &a,string &b){
        if(i>=n || j>=n) 
            return 0;
        int  take=0;
        int not_take=0; 
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j])
              take=1+solve(i+1,j+1,a,b);
        else
            not_take=max(solve(i+1,j,a,b),solve(i,j+1,a,b));
        return dp[i][j]=max(take,not_take);
    }
public:
    int longestPalindromeSubseq(string s) {
         n=s.size(); 
        string a=s;
        reverse(a.begin(),a.end()); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,a,s);
    }
};