int dp[203][204];
class Solution { 
    private: 
    int n,m;
     int solve(int i,int j,vector<vector<int>>&tri){
         if(i>=n)
             return 0;
         if(dp[i][j]!=-1){
             return dp[i][j];
         }
         int left=tri[i][j]+solve(i+1,j,tri);
         int down=tri[i][j]+solve(i+1,j+1,tri);
         return dp[i][j]=min(left,down);
     }
public:
    int minimumTotal(vector<vector<int>>& tri) {
             n=tri.size();
             m=tri[0].size(); 
             memset(dp,-1,sizeof(dp));
            return solve(0,0,tri); 
    }
};