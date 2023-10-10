int dp[502][502];
class Solution {
    private:
    int n,m;
    int solve(int i,int j,string &w1,string &w2){
         if(i>=n && j>=m){
              return 0;
         }
         if(i>=n){
             return m-j;
         }
         if(j>=m){
              return n-i;
         }
          if(dp[i][j]!=-1)
               return dp[i][j];
         int equal=INT_MAX;
        int not_equal=INT_MAX;
        if(w1[i]==w2[j]){
            equal=solve(i+1,j+1,w1,w2);
        }
        else{
            not_equal=min(1+solve(i,j+1,w1,w2),min(1+solve(i+1,j,w1,w2),1+solve(i+1,j+1,w1,w2)));
        }
        return dp[i][j]=min(equal,not_equal);
    }
public:
    int minDistance(string w1, string w2) {
        n=w1.size();
        m=w2.size();
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;++i){
            dp[i][0]=i;  // deleteions
        }
        for(int j=0;j<=m;++j){
            dp[0][j]=j;
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                int equal=1e9;
                int not_equal=1e9;
                if(w1[i-1]==w2[j-1]){
                    equal=dp[i-1][j-1];
                }
                else{
                    not_equal=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
                dp[i][j]=min(equal,not_equal);
            }
        }
        return dp[n][m];
        
    }
};