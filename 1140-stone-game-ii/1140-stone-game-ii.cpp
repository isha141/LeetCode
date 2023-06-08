int dp[105][105][2];
class Solution { 
    private:
    int n;
    long long solve(int i,vector<int>&p,int count,bool flag){
        if(i>=n) return 0; 
        long long take=0; 
        if(dp[i][count][flag]!=-1)
            return dp[i][count][flag];
        if(flag==1)
            take=INT_MAX;
        if(!flag){
             int c=0; 
            long temp=0;
            for(int j=1;(j<=2*count && (j+i-1)<n);++j){ 
                 c+=1;
                 temp+=p[j+i-1];
                take=max(take,temp+solve(i+c,p,max(count,c),!flag));
            }
        }
        else{
             int c=0; 
             long temp=0;
            for(int j=1;(j<=2*count && (j+i-1)<n);++j){ 
                 c+=1; 
                temp+=p[j+i-1];
                take=min(take,solve(i+c,p,max(count,c),!flag));
            } 
        }
        return dp[i][count][flag]=take;
    }
public:
    int stoneGameII(vector<int>& p) {
           n=p.size(); 
           memset(dp,-1,sizeof(dp));
           return solve(0,p,1,0);
    }
};