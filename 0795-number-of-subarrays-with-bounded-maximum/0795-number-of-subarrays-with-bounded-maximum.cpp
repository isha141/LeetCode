class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int c=0;
        int start=-1;
        int end=-1;
        int i=0; 
        int maxi=0;
        for(i=0;i<n;++i){ 
            // maxi=max(maxi,nums[i]);
            if(nums[i]>right){
                  start=i;
                end=i;
            }
            if(nums[i]>=left)
                end=i;
                c+=end-start;
        }
        // c+=i-start;
        return c;
    }
};