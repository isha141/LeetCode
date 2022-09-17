class Solution { 
    private:
    int n,m;
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
         n=nums.size();
         m=mul.size(); 
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=i;--j){
                int pick=0;
                int not_pick=0; 
                pick=nums[i]*mul[j]+dp[i+1][j+1];
                not_pick=nums[n-(j-i)-1]*mul[j]+dp[i][j+1];
                dp[i][j]=max(pick,not_pick);
            }
        }
        return dp[0][0];
    }
};