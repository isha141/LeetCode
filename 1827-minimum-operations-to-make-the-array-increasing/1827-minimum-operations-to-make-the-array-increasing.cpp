class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int prev=nums[0];
        int c=0;
        for(int i=1;i<n;++i){
            if(nums[i]<=prev){
             c+=prev+1-nums[i]; 
                prev+=1;
            }
            else
            prev=nums[i];
        }
        return c;
    }
};