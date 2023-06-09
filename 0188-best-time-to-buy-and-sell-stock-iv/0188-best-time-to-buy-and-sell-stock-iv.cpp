long long dp[1005][105][2];
class Solution { 
    private:
    int n;
    long long solve(int i,vector<int>&p,int k,bool flag){ 
          if(i>=n && flag){
                return -1e9;
          } 
           if(k<=0){
               return 0;
           }
           if(i>=n) 
               return 0 ;  
        if(dp[i][k][flag]!=-1)
             return dp[i][k][flag];
        long long take=INT_MIN; 
        long long not_take=INT_MIN;
        if(!flag){
            take=max(solve(i+1,p,k,flag),-p[i]+solve(i+1,p,k,!flag));
        }
        else{
            not_take=max(solve(i+1,p,k,flag),p[i]+solve(i+1,p,k-1,!flag));
        }
        return dp[i][k][flag]=max(take,not_take);
    }
public:
    int maxProfit(int k, vector<int>& p) {
         n=p.size(); 
        memset(dp,-1,sizeof(dp));
        return solve(0,p,k,0);
    }
};