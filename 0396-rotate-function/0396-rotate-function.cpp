class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans=0; 
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;++i){
            ans+=nums[i]*i;
            sum+=nums[i];
        }
        int maxi=INT_MIN; 
        maxi=max(maxi,ans);
       int prev=ans;
        int k=n-1;
        for(int i=1;i<n;++i){
            int ans=prev+sum-(n*nums[k]);
            prev=ans;
            k--;
            maxi=max(maxi,prev);
        }
        return maxi;
    }
};