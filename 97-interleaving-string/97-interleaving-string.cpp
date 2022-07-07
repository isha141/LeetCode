int dp[105][105];
class Solution { 
    int solve(string &s1,string &s2,string &s3,int i=0,int j=0,int k=0)
    {
        if(i>=s1.size() && j>=s2.size() && k>=s3.size())
            return 1;  
        int left=0;
        int right=0; 
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<s1.size() && s1[i]==s3[k]){ 
          left|=solve(s1,s2,s3,i+1,j,k+1);
        }
        if(j<s2.size() && s2[j]==s3[k]){
         left|=solve(s1,s2,s3,i,j+1,k+1);
         }
      return dp[i][j]=left;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();
        int n=s2.size();
        int o=s3.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,s3);
    }
};