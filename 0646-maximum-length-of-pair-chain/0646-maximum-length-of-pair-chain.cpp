int dp[1001][2003];
class Solution {
    private:
    int n;
    int solve(int i,vector<vector<int>>&pair,int prev){
        if(i>=n)
              return 0;
        if(dp[i][prev+1000]!=-1)
             return dp[i][prev+1000];
        int take=0;
        int not_take=0;
        if(prev==-1000 || (prev<pair[i][0] && pair[i][0]<pair[i][1])){
            take=1+solve(i+1,pair,pair[i][1]);
        }
        not_take=solve(i+1,pair,prev);
        return dp[i][prev+1000]=max(take,not_take);
    }
public:
    
    int findLongestChain(vector<vector<int>>& pair) {
        n=pair.size(); 
        sort(pair.begin(),pair.end()); 
        memset(dp,-1,sizeof(dp));
        return solve(0,pair,-1000);
    }
};