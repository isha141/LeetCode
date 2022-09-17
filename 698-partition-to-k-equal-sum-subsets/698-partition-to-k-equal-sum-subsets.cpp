class Solution { 
    private:
    int n;
    int solve(int ind,vector<int>&nums,int sum,int &target,int k,vector<bool>&vis){
        if(k==1) return 1;
        if(sum==target)
            return solve(0,nums,0,target,k-1,vis);  
        if(ind>=n)
            return 0;
        for(int i=ind;i<n;++i){
            if(vis[i] || sum+nums[i]>target) 
                continue;
            
            vis[i]=1;
            if(solve(i+1,nums,sum+nums[i],target,k,vis))
                return 1;
            vis[i]=0; 
            if(sum==0) break;
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int sum=0;
        for(auto itr: nums)  sum+=itr;
        if(sum%k || k>n) return 0; 
        vector<bool>vis(n,0); 
        int tar=sum/k;
        sort(nums.rbegin(),nums.rend());
        return solve(0,nums,0,tar,k,vis);
    }
};