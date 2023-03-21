class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        long long ans=0; 
        int low=0;
        int high=0;
        while(high<n){
            if(nums[high]==0){
                int j=high;
                while(j<n && nums[j]==0) 
                    j++;
                ans+=(1ll*(j-low)*(j-low+1))/2; 
                low=j;
                high=j;
                // j=low;
            }
            else{
                high++;
                low=high;
            }
        }
        return ans;
    }
};