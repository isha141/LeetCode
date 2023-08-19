class Solution { 
    int n;
    long long solve(long mid,vector<int>&nums,vector<int>&cost){
        long long sum=0;
        for(int i=0;i<n;++i){
            long temp=abs(mid-nums[i]);
            sum+=(1ll*temp*cost[i]);
        }
        return sum;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) { 
        n=nums.size();
         long long  ans=LONG_MAX; 
        long low=1;
        long high=1e6;
        while(low<=high){
             long mid=(low+high)>>1;
            long long temp=solve(mid,nums,cost);
            long long temp1=solve(mid+1,nums,cost);
            ans=min(ans,temp);
             ans=min(ans,temp1);
            if(temp<temp1){     
                high=mid-1;
            }
            else{
                  low=mid+1;
            }
        }
         return ans;
        
    }
};