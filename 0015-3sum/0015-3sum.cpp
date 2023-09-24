class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            int temp=-nums[i];
            int low=i+1;
            int high=n-1;
            while(low<high){
                if(nums[low]+nums[high]==temp){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    int j=low+1;
                    while(j<n && nums[j]==nums[low])
                         j++;
                    low=j;
                    j=high-1;
                    while(j>low && nums[j]==nums[high])
                        j--;
                    high=j;
                }
                else if(nums[low]+nums[high]<temp){
                    low+=1;
                }
                else{
                    high-=1;
                }
            }
            int j=i+1;
            while(j<n && nums[i]==nums[j])
                 j+=1;
            i=j;
        }
        return ans;
    }
};