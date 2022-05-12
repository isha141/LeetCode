class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
        sort(nums.begin(),nums.end());
        int k=0;
        int n=nums.size();
        int i=0;
        while(i<n-1)
        {
            if(nums[i]==nums[i+1]){
                ans.push_back(nums[i]);
                i+=2;
            }
            else
                i++;
        }
        return ans;
    }
};