int dp[105][205];
class Solution {
    private:
    int n;
    int ans=0;
    int mod=1e9+7; 
     int solve(int start,int finish,int fuel,int cost,vector<int>&loc){
           if(cost>fuel){ 
                  return 0 ;
           }
         if(dp[start][cost]!=-1)
               return  dp[start][cost]; 
         long ans=0;
           if(start==finish){
               ans=1;
           }
         for(int i=0;i<n;++i){
             if(start!=i){
                 ans =(ans%mod+solve(i,finish,fuel,cost+abs(loc[i]-loc[start]),loc))%mod;  
             }
         } 
         return dp[start][cost]=ans%mod;
     }
public:
    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {  
          n=loc.size(); 
           memset(dp,-1,sizeof(dp));
           return solve(start,finish,fuel,0,loc);  
    }
};