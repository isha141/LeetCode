// int dp[502][502];
class Solution {
    private:
    int n;
    int m;
    // int solve(int i,int j,string &a,string &b){
    //     if(i<0)
    //           return j+1;
    //     if(j<0) return i+1;
    //     int take=INT_MAX;
    //     int not_take=INT_MAX;
    //     if(dp[i][j]!=-1)
    //           return dp[i][j];
    //     if(a[i]==b[j])
    //         take=solve(i-1,j-1,a,b);
    //      not_take=1+min(solve(i-1,j,a,b),min(solve(i,j-1,a,b),solve(i-1,j-1,a,b)));
    //     return dp[i][j]=min(take,not_take);
    // }
public:
    int minDistance(string a, string b) {
         n=a.size();
         m=b.size(); 
         if(a==b) return 0;
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i=0;i<=n;++i){
             dp[i][0]=i;
         }
         for(int i=0;i<=m;++i){
             dp[0][i]=i;
         }
         for(int i=1;i<=n;++i){
             for(int j=1;j<=m;++j){
                 if(a[i-1]==b[j-1])
                 dp[i][j]=dp[i-1][j-1];
                 else
                 dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
             }
         }
         return dp[n][m];
    }
};