class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int ans=0; 
        int i=0;
        int j=0;
        while(j<n-1){
            int far=0;
            for(int k=i;k<=j;++k){
                far=max(far,nums[k]+k);
            }
            ans++;
            i=j+1;
            j=far;
        }
        return ans;
        
    }
};