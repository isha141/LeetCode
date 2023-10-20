int dp[301][301];
class Solution {
    private:
    int solve(int i,int j,vector<int>&nums){
        if(i>j) return 0;
        int ans=0;
        int maxi=0;
        if(dp[i][j]!=-1)
             return dp[i][j];
        for(int k=i;k<=j;++k){
            ans=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums);
            maxi=max(maxi,ans);
        }
        return dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        memset(dp,-1,sizeof(dp));
        return solve(1,n,nums);
    }
};