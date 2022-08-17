class Solution { 
    private:
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0; 
        for(auto itr: nums)
            sum+=itr;
        if(sum%2)
            return 0;
        sum/=2;
        // vector<vector<int>>dp(n,vector<int>(sum+1,0)); 
    // for(int i=0;i<n;++i)
    //     dp[i][0]=1;  
        vector<int>prev(sum+1,0);
        if(nums[0]<=sum)
        prev[nums[0]]=1;
        for(int i=1;i<n;++i){
            vector<int>curr(sum+1,0); 
            curr[0]=1;
            for(int k=1;k<=sum;++k){
                int pick=0;
                int not_pick=prev[k];
                if(nums[i]<=k)
                    pick=prev[k-nums[i]];
                curr[k]=(pick|| not_pick);
            } 
            prev=curr;
        }
        return prev[sum];
    }
};