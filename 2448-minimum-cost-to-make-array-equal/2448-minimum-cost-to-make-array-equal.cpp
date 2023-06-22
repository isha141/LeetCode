class Solution { 
    private:
    int n;
    long long ans=LONG_MAX; 
    long long solve(long long mid,vector<int>&nums,vector<int>&cost){
        long long res=0;
        for(int i=0;i<n;++i){ 
            long long temp=abs(nums[i]-mid);
            res+=(1ll*(temp)*(cost[i]));
        }
        return res;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
          n=nums.size();
          long long low=0;
          long long high=1000000; 
        // ans=solve(1,nums,cost);
        while(low<high){
            long long mid=(low+high)/2;
            long long t1=solve(mid,nums,cost);
            long long t2=solve(mid+1,nums,cost); 
             ans=min(ans,t1);
              ans=min(ans,t2);
            if(t1<t2){
                high=mid;
            }
            else{ 
                low=mid+1;
            }
        }
        return ans;
    }
};