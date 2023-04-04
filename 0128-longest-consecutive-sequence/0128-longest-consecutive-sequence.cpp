class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int n=nums.size();
        if(n==1)
             return 1;
        int ans=0; 
        map<int,int>mp;
        for(int i=0;i<n;++i){ 
            if(mp.find(nums[i]-1)!=mp.end()){
                ans=max(ans,mp[nums[i]-1]+1);
                mp[nums[i]]=mp[nums[i]-1]+1;
            }
            else{
                mp[nums[i]]=1; 
                ans=max(ans,1);
            }
        }
        return ans;
    }
};