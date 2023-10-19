int dp[2501][2502];
class Solution {
    private:
    int n;
    int solve(int i,vector<int>&nums,int last){
        if(i>=n) return 0;
        int take=0;
        int not_take=0;
        if(dp[i][last+1]!=-1)
             return dp[i][last+1];
        if(last==-1 || nums[last]<nums[i])
            take=1+solve(i+1,nums,i);
        not_take=solve(i+1,nums,last);
        return dp[i][last+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<int>ds;
        for(int i=0;i<n;++i){
            if(ds.size()==0){
                ds.push_back(nums[i]);
                continue;
            }
            if(ds.size() && ds.back()<nums[i]){
                ds.push_back(nums[i]);
            }
            else{
                auto itr=lower_bound(ds.begin(),ds.end(),nums[i])-ds.begin();
                ds[itr]=nums[i];
            }
        }
        return ds.size();
    }
};