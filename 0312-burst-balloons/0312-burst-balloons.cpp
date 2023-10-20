// int dp[301][301];
class Solution {
    private:
    // int solve(int i,int j,vector<int>&nums){
    //     if(i>j) return 0;
    //     int ans=0;
    //     int maxi=0;
    //     if(dp[i][j]!=-1)
    //          return dp[i][j];
    //     for(int k=i;k<=j;++k){
    //         ans=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums);
    //         maxi=max(maxi,ans);
    //     }
    //     return dp[i][j]=maxi;
    // }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+4,vector<int>(n+4,0));
        for(int i=n;i>=1;--i){
            for(int j=1;j<=n;++j){
                if(i>j) continue;
                int maxi=0;
                for(int k=i;k<=j;++k){
                    int ans=nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    maxi=max(maxi,ans);
                }
                dp[i][j]=maxi;
            }
        }
         return dp[1][n];
    }
};