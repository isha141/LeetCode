class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0;
        int high=0;  
        int pr=1; 
        int count=0;
        for(int i=high;i<n;++i){
            pr=nums[i]*pr;
            while(pr>=k && low<=i){
                pr=pr/nums[low++];
            }
            count+=(i-low+1);
        }
        return count;
    }
};