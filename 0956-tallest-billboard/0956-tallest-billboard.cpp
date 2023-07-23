int dp[21][10001];
class Solution { 
    private:
      int n;  
      int sum;
      int solve(int i,vector<int>&rods,int n,int s1,int s2){
          if(i>=n){ 
               if(s1==0) 
                    return 0;
              return INT_MIN;
          } 
          // if(s1<0) return 0;
          if(dp[i][s1+5000]!=-1) 
              return dp[i][s1+5000];
          int left=rods[i]+solve(i+1,rods,n,s1+rods[i],s2);
          int take=solve(i+1,rods,n,s1-rods[i],s2); 
          int not_take=solve(i+1,rods,n,s1,s2);
          return dp[i][s1+5000]=max(left,max(take,not_take));
      }
public:
    int tallestBillboard(vector<int>& rods) {
        int sum=0; 
         n=rods.size();
          memset(dp,-1,sizeof(dp));
          return solve(0,rods,n,0,0);
    }
};