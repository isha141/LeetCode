int dp[1005][1005][3];
class Solution { 
    vector<int>nums;
    private:
    int solve(int ind,int flag,int val){
        if(ind>=nums.size())
            return 0; 
        if(val==-1)
            return max(solve(ind+1,flag,nums[ind]),solve(ind+1,flag,val));
        if(dp[ind][val][flag]!=-1)
            return dp[ind][val][flag];
        int take=0;
        if(flag && nums[ind]-val>0){
            take=solve(ind+1,1^flag,nums[ind])+1;
        }
        if(!flag && nums[ind]-val<0){
            take=solve(ind+1,1^ flag,nums[ind])+1;
        }
        take=max(take,solve(ind+1,flag,val)); 
       return dp[ind][val][flag]=take;
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();  
        memset(dp,-1,sizeof(dp));
        this->nums=nums;
        return max(solve(0,0,-1),solve(0,1,-1))+1;
    }
};