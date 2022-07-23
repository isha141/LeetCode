class Solution { 
    private:
    // long  solve(int i,int j,vector<int>&cuts,vector<vector<int>>&dp)
    // {
    //     if(i>j) return 0; 
    //     int mini=1e9; 
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     for(int k=i;k<=j;++k){
    //         int cost=(cuts[j+1]-cuts[i-1])+solve(i,k-1,cuts,dp)+solve(k+1,j,cuts,dp); 
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
public:
    int minCost(int n, vector<int>& cuts) { 
        cuts.push_back(n);
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end()); 
        vector<vector<int>>dp(cuts.size()+2,vector<int>(cuts.size()+2,0));
        for(int i=cuts.size()-2;i>=1;--i){
            for(int j=1;j<=cuts.size()-2;++j){ 
                int mini=1e9; 
                if(i>j)
                    continue;
                for(int k=i;k<=j;++k){
                int cost=cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j];
                mini=min(mini,cost);
            }
            dp[i][j]=mini;
            }
        }
       return dp[1][cuts.size()-2]; 
    }
};