// int dp[1000][1000];
class Solution { 
    private: 
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(); 
        int ans=0; 
        unordered_map<int,int>dp[n+1];
        for(int i=1;i<n;++i){
            for(int j=0;j<i;++j){ 
              int cnt=1;
                int diff=nums[i]-nums[j];
                if(dp[j].count(diff))
                    cnt=dp[j][diff]; 
                dp[i][diff]=cnt+1;
                ans=max(ans,dp[i][diff]);
        }
        }
        return ans;
    }
};