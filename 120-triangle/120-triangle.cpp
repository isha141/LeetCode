class Solution { 
    private:
//     int solve(int i,int j,vector<vector<int>>& t,vector<vector<int>>&dp){
//         if(i==t.size()-1)  
//             return t[i][j];
//         if(j<0 || j>=t[i].size())
//             return INT_MAX;  
//         if(dp[i][j]!=-1) return dp[i][j];
//         int left= t[i][j]+ solve(i+1,j,t,dp); 
//         int right=t[i][j]+solve(i+1,j+1,t,dp);
//         return dp[i][j]= min(left,right);
            
//         }
public:
    int minimumTotal(vector<vector<int>>& t) {
        int n=t.size(); 
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        dp[n-1]=t[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[i][j]= t[i][j]+ min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
        
       
    }
};