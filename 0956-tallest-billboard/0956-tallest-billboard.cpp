int dp[25][2*5000+1];
class Solution { 
    private:
    int n; 
    int total=0;
    int ans=0;
    int solve(int i,int r1,int r2,vector<int>&rods){
        if(i>=n){
            if(r1==0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][r1+5000]!=-1)
             return dp[i][r1+5000];
        int op1=rods[i]+solve(i+1,r1+rods[i],r2,rods);
        int op2=solve(i+1,r1-rods[i],r2,rods);
        int op3=solve(i+1,r1,r2,rods);
        return dp[i][r1+5000]=max(op1,max(op2,op3));
    }
public:
    int tallestBillboard(vector<int>& rods) {
         n=rods.size();    
         for(auto itr: rods)
              total+=itr;
          memset(dp,-1,sizeof(dp));
          return solve(0,0,0,rods);
        // return ans;
    }
};