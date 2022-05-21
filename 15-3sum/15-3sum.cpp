class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=0;
        int n=nums.size();
        while(i<n)
        {
            int temp=-1 *nums[i];
            int low=i+1;
            int high=n-1;
            while(low<high)
            {
                if(nums[low]+nums[high]==temp)
                {
                    ans.push_back({-temp,nums[low],nums[high]});
                    while(low+1<n && nums[low]==nums[low+1])
                        low++;
                    low++;  
                    int temp=nums[high];
                    while(high>low && nums[high]==temp)
                        high--;
                }
                else if(nums[low]+nums[high]<temp)
                    low++;
                else
                    high--;
            }
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};