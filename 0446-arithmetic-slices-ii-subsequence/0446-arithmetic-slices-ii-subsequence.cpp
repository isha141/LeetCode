class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(); 
        int c=0;
        vector<map<long long,int>>dp(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<i;++j){ 
                int ans=0;
                long long diff=(long long)nums[i]-(long long)nums[j];
                dp[i][diff]+=1;
                if(dp[j].count(diff)){
                    dp[i][diff]+=dp[j][diff];
                    c+=dp[j][diff];
                }
            }
        }
        return c;
    }
};