class Solution { 
    private:
    int solve(int ind,vector<int>&nums,int n,vector<int>&dp)
    {  
        
        if(ind>=n-1)
            return 0;  
        if(dp[ind]!=-1)
            return dp[ind];
       int temp=1e9;
        int steps=nums[ind];
        for(int i=1;i<=steps;++i){
            temp=min(1+solve(i+ind,nums,n,dp),temp); 
            // co//ut<<temp<<" in"<<endl;;
        }  
        //cout<<temp<<"out"<<endl;
        // cout<<endl; 
        
        return dp[ind]=temp;
    }
public:
    int jump(vector<int>& nums) {
        int n=nums.size(); 
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};