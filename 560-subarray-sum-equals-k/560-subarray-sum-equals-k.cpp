class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int count=0; 
        int n=nums.size();
        int sum=0; 
        mp[0]=1;
        for(int i=0;i<n;++i){
            sum+=nums[i];
            if(mp.count(sum-k)){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};