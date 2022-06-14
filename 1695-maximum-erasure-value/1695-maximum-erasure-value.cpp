class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0; 
        int ans=INT_MIN;
        int sum=0;
        map<int,int>mp;
        while(right<n){
            int num=nums[right]; 
            mp[num]++; 
            sum+=num;
            right++;
            while(mp[num]>1){
                sum-=nums[left]; 
                mp[nums[left]]--;
                left++;
            } 
            ans=max(ans,sum);
        }
        return ans;
    }
};