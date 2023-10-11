int dp[303][303];
class Solution { 
    private:
    int n;
    int solve(int i,int j,vector<int>&nums){
         if(i>j) return 0;
          int ans=0;
          if(dp[i][j]!=-1)
            return dp[i][j];
          for(int k=i;k<=j;++k){
              int vals=1ll*nums[k];
              // if(i-1>=0)
                   vals*=nums[i-1];
              // if(j+1<n)
                    vals*=nums[j+1];
              ans=max(ans,vals+solve(i,k-1,nums)+solve(k+1,j,nums));
          }
        return dp[i][j]=ans;
    }
public:
    int maxCoins(vector<int>& nums) { 
        n=nums.size();
         nums.push_back(1);
        nums.insert(nums.begin(),1);   
         memset(dp,-1,sizeof(dp));
        return solve(1,n,nums);
    }
};