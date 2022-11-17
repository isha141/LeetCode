class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0; 
        int ans=1e9;
        int sum=0;
        int high=n-1;
        while(low<high){  
            int tot=nums[low];
            int i=low+1; 
            int j=high;
            while(i<j){ 
              if(tot+nums[i]+nums[j]==target)
                  return target;
                if(tot+nums[i]+nums[j]<target)
                {
                    if(abs(target-(tot+nums[i]+nums[j]))<ans){
                        sum=tot+nums[i]+nums[j];
                        ans=abs(target-(tot+nums[i]+nums[j]));
                    }
                    i++;
                }
                else{
                    if(abs(target-(tot+nums[i]+nums[j]))<ans){
                        sum=tot+nums[i]+nums[j];
                        ans=abs(target-(tot+nums[i]+nums[j]));
                    }
                     j--;
                }
            }
            low++;
        }
        return sum;
    }
};