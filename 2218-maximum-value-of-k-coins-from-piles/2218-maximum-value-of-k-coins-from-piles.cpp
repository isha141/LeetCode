int dp[1003][2003];
class Solution { 
    int n; 
    int solve(int i,int j,vector<vector<int>>&p,int k){
        if(k<0){
            return 0;
        }
        if(i>=n) {
            if(k==0) return 0; 
             return INT_MIN;
        }  
        if(dp[i][k]!=-1) 
             return dp[i][k];
        int take=0;
        int not_take=0;
        int curr=0;
        not_take=solve(i+1,j,p,k);
        for(int l=0;l<p[i].size() && l<k;++l){
            curr+=p[i][l];
            take=max(take,curr+solve(i+1,j,p,k-l-1));
        }
        return dp[i][k]=max(take,not_take);
    }
public:
    int maxValueOfCoins(vector<vector<int>>& p, int k) {
            n=p.size(); 
          memset(dp,-1,sizeof(dp));
          return solve(0,0,p,k);
    }
};