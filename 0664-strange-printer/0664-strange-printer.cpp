int dp[102][102];
class Solution {
    private:
    int n;
    int solve(int l,int r,string &s){
            if(l==r) return 1;
            if(l>=r) return 0;
            int ans=INT_MAX;
            if(dp[l][r]!=-1)
                 return dp[l][r];
            int i=l+1;
            while(i<=r && s[i]==s[l]){
                i++;
            }
            if(i==r+1) 
                return 1;
            ans=1+solve(i,r,s);
            int temp=INT_MAX;
            for(int j=i;j<=r;++j){
                if(s[j]==s[l]){
                   int temp1=solve(i,j-1,s)+solve(j,r,s);
                    temp=min(temp,temp1);
                }
            }
          return dp[l][r]=min(temp,ans);
    }
public:
    int strangePrinter(string s) {
         n=s.size();
         memset(dp,-1,sizeof(dp));
        return solve(0,n-1,s);  
    }
};