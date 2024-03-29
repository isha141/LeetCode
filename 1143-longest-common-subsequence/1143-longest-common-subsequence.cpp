class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
         if(i==0 && j==0)
             return a[0]==b[0];
        int l=0;
        int r=0; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i]==b[j])
            l=1+solve(i-1,j-1,a,b,dp);
        else{
            r=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp));
        }
        return dp[i][j]=max(l,r);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size(); 
        vector<int>prev(n+1,0); 
        for(int i=1;i<=m;++i){ 
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;++j){ 
                int l=0;
                int r=0;
                if(text1[i-1]==text2[j-1]){
                    l=1+prev[j-1];
                }
                r=max(prev[j],curr[j-1]);
                curr[j]=max(l,r);
            } 
            prev=curr;
        }
        return prev[n];
    }
};