class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int temp=nums[i];
            int res=target-nums[i];
            int j=i+1,h=n-1;
            while(j<=h){
                int mid=(j+h)/2;
                if(nums[mid]==res){
                    return {i+1,mid+1};
                }
                else if(nums[mid]<=res){
                    j=mid+1;
                }
                else
                    h=mid-1;
            }
            i++;
        }
        return {};
    }
};