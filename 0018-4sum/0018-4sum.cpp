class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size(); 
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;){
            for(int j=i+1;j<n-2;){
                long long tot=nums[i]+nums[j];
                long long  rem=target-tot;
                int low=j+1;
                int high=n-1;
                while(low<high){
                    if(nums[low]+nums[high]==rem){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        int k=low;
                        while(k<high && nums[k]==nums[low])
                            k++;
                        low=k;
                        int l=high;
                        while(l>low && nums[l]==nums[high])
                            l--;
                        high=l;
                        // high--; 
                        continue;
                    }
                    else if(nums[low]+nums[high]<rem)
                          low++;
                    else
                        high--;
                }
                low=j;
                while(j<n && nums[low]==nums[j])
                    j++;
            }
            int low=i;
            while(i<n && nums[low]==nums[i])
                i++;
        }
        return ans;
    }
};