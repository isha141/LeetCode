long long dp[100005];
class Solution {
    private: 
    int n;
    long long solve(int ind,vector<vector<int>>&q){
        if(ind>=n) return 0; 
        if(dp[ind]!=-1)
             return dp[ind];
        long long take=0,not_take=0;
        take=q[ind][0]+solve(ind+q[ind][1]+1,q); 
        not_take=solve(ind+1,q);
         return dp[ind]=max(take,not_take);
    }
public:
    long long mostPoints(vector<vector<int>>& q) {
           n=q.size();
         long long ans=0; 
        memset(dp,-1,sizeof(dp));
         return solve(0,q);
    }
};