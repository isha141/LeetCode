class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i){ 
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;++j){ 
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int sum=nums[i]+nums[j];
                int low=j+1;
                int high=n-1;
                while(low<high){
                    if((1ll*nums[low]+nums[high]+sum)==target){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                    int prev=low;
                    while(low<high && nums[prev]==nums[low]){
                         low++;
                    }
                    prev=high;
                    while(high>low && nums[prev]==nums[high]){
                        high--;
                    } 
                    }
                    else if((1ll*nums[low]+nums[high]+sum)<target){
                    low++;
                   }
                   else{
                    high--;
                   } 
                }
            }
        }
        return ans;
    }
};