class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;++i){
            int temp=nums[i]; 
            int len=1;
            for(int j=i+1;j<n;++j){
                if((temp xor nums[j])==temp+nums[j]){
                    len++; 
                    temp+=nums[j];
               }
                else
                    break;
            }
            ans=max(ans,len);
        }
        return ans;
    }
};