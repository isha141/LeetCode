class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans=LONG_MAX; 
        int n=nums.size();
        vector<long long>ds(n,INT_MAX);
        for(int i=0;i<n;++i){
            long long sum=0;
            for(int j=0;j<n;++j){
                ds[j]=min(ds[j],1ll*nums[(i+j)%n]);
                 sum+=ds[j];
            }
            sum+=(1ll*i)*x;
            ans=min(ans,sum);
        }
        return ans;
    }
};