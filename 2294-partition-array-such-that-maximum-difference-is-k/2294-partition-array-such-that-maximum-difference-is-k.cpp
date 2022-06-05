class Solution {
public:
    int partitionArray(vector<int>& nums, int k) { 
        int n=nums.size();
        sort(nums.begin(),nums.end()); 
        int prev=0;
        int cnt=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-nums[prev]<=k)
                continue;
            cnt++;
            prev=i;
        }
        return cnt;
        
        
    }
};