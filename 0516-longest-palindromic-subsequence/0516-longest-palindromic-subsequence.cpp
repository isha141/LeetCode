class Solution { 
    private:
    int solve(int i,int j,string &a,string &b,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
            return 0;
        if(i==0 && j==0)
            return a[0]==b[0];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l=0;
        int r=0;
        if(a[i]==b[j])
            l=1+solve(i-1,j-1,a,b,dp);
          r=max(solve(i-1,j,a,b,dp),solve(i,j-1,a,b,dp)); 
        return dp[i][j]=max(l,r);
    }
public:
    int longestPalindromeSubseq(string s) { 
        string ans=s;
        reverse(ans.begin(),ans.end());  
        int n=ans.size();
        vector<int>prev(n+10);
        for(int i=1;i<=n;++i){ 
            vector<int>curr(n+1,0);
            for(int j=1;j<=n;++j){
                if(s[i-1]==ans[j-1])
                    curr[j]=1+prev[j-1];
                else
                curr[j]=max(prev[j],curr[j-1]);
            } 
            prev=curr;
        }
        return prev[n];
    }
};