class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long currsum=0;
        for(auto itr: nums)
            sum+=itr;
        int mini=n-1;
        long long ans=(int)1e9;
        for(int i=0;i<n-1;++i){
            currsum+=nums[i];
            long long diff=abs(currsum/(i+1)-abs(sum-currsum)/(n-i-1));
            if(ans>diff){
                ans=diff;
                mini=i;
            }
        }
        if(ans>sum/n){
           return n-1;
        }
        return mini;
    }
};