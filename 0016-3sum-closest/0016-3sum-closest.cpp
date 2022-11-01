class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       int diff=1e9;
        int sum=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        while(i<n-2){ 
            int j=i+1;
            int k=n-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(diff>abs(sum-target)){
                    diff=abs(sum-target);
                    ans=sum;
                }
                if(sum<target)
                    j++;
                else
                    k--;
            }
            i++;
        }
        return ans;
    }
};