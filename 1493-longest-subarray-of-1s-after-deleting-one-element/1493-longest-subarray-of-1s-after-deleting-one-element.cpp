class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int n=nums.size();
         int ans=0;
        int last=0;
        bool flag=0;
        int c=0; 
        int prev=-1;
        for(int i=0;i<n;++i){
            if(nums[i]==1){
                c+=1; continue;
            }
            else if(!flag){
                  flag=1;
                prev=i;
            }
            else{
                flag=1;
                ans=max(ans,c);
                c=i-prev-1;
                prev=i;
                
            }
        } 
        ans=max(ans,c); 
        if(ans==n) return ans-1;
        return ans;
    }
};