int dp[101][101][2];
class Solution { 
    private:
    int n;
    int solve(int i,vector<int>&p,int m,bool flag){
        if(i>=n)
              return 0; 
        int take=0; 
        int not_take=INT_MAX;
        if(flag)
            take=INT_MAX; 
        if(dp[i][m][flag]!=-1)
             return dp[i][m][flag];
        if(!flag){
             int count=0; 
             int sum=0;
            for(int j=i;j<n && count<2*m;++j){
                count+=1; 
                sum+=p[j];
                take=max(take,sum+solve(j+1,p,max(m,count),!flag));
            }
        }
        else{
             int count=0; 
             int sum=0;
            for(int j=i;j<n && count<2*m;++j){
                count+=1;
                sum+=p[j];
                take=min(take,solve(j+1,p,max(m,count),!flag));
            }
        }
        return dp[i][m][flag]=take;
    }
public:
    int stoneGameII(vector<int>& p) {
        n=p.size(); 
        memset(dp,-1,sizeof(dp));
         return solve(0,p,1,0);
    }
};