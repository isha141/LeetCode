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
             vector<vector<int>>dp(n,vector<int>(204,1e9));
             dp[0][0]=tri[0][0];
             for(int i=1;i<n;++i){
                 for(int j=0;j<tri[i].size();++j){
                     int temp=tri[i][j];
                     if(j<tri[i-1].size()){
                         temp+=dp[i-1][j];
                     } 
                     else temp=INT_MAX;
                     int down=tri[i][j];
                     if(j>0){
                         down+=dp[i-1][j-1];
                     } 
                     else
                         down=INT_MAX;
                     dp[i][j]=min(temp,down);
                 } 
             } 
        int ans=INT_MAX;
           for(int j=0;j<tri[n-1].size();++j){
              ans=min(ans,dp[n-1][j]);
           }
        return ans;
        
    }
};