int dp[105][105];
class Solution { 
    int solve(int i,int j,int k,string &s1,string &s2,string &s3)
    {
        if(i==s1.size() && j==s2.size() && k==s3.size())
            return 1;  
        int left=0;
        int right=0; 
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.size() && s1[i]==s3[k]){ 
          left=solve(i+1,j,k+1,s1,s2,s3);
        }
        if(j<s2.size() && s2[j]==s3[k]){
         right=solve(i,j+1,k+1,s1,s2,s3);
         }
      return dp[i][j]=(left|| right);
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int o=s3.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s1,s2,s3);
    }
};