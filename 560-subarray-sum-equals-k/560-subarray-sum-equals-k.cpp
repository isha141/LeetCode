class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int sum=0; 
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k)
                count++;
            if(mp.count(sum-k))
                count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
}; 