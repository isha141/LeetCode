int dp[105][105];
class Solution { 
    private:
    int n,m;
    int solve(int i,int j,int k,string &a,string &b,string &c){
        if(i>=a.size() && j>=b.size() && k>=c.size())
            return 1;
        bool left=0; 
        bool right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<n && a[i]==c[k])
            left=solve(i+1,j,k+1,a,b,c);
        if(j<m && b[j]==c[k])
            right=solve(i,j+1,k+1,a,b,c);
        return dp[i][j]=(left| right);
    }
public:  
    bool isInterleave(string s1, string s2, string s3) {
         n=s1.size();
         m=s2.size();
        int t=s3.size();
        if(t!=(m+n)) return 0;  
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s1,s2,s3);
    }
};