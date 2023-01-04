class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size(); 
        vector<int>dp(n,0);
        vector<int>hash(n,0); 
        int maxi=0; 
        sort(nums.begin(),nums.end());
        int ind=0;
        for(int i=0;i<n;++i){ 
            hash[i]=i;
            for(int j=0;j<i;++j){ 
                if(nums[i]%nums[j]==0  && (dp[i]<dp[j]+1)){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                 ind=i;
            }
        } 
        // cout<<ind<<" ";
        // for(int i=0;i<n;++i) cout<<hash[i]<<" ";
        // cout<<endl;
        while(hash[ind]!=ind){
            ans.push_back(nums[ind]);
            ind=hash[ind];
        } 
        ans.push_back(nums[ind]);
        return ans;
    }
};