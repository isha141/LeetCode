class Solution { 
    private:
    int solve(int i,int j,vector<int>& nums,int n,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        int maxi=INT_MIN; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<=j;++k){
            int temp=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,n,dp)+ solve(k+1,j,nums,n,dp);
            maxi=max(maxi,temp);
            
        }
        return  dp[i][j]=maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size(); 
        nums.push_back(1); 
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        nums.insert(nums.begin(),1);
        for(int i=n;i>=1;--i){
            for(int j=1;j<=n;++j){  
                if(i>j)
                    continue;
                int maxi=INT_MIN;
                for(int k=i;k<=j;++k){
                    int cost= nums[i-1]*nums[k]*nums[j+1]+ dp[i][k-1]+ dp[k+1][j];
                    maxi=max(maxi,cost);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};