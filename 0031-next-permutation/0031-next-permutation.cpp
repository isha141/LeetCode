class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int first=-1;
         int second=-1;
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                first=i;
                break;
            }
        }
        if(first==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;--i){
            if(nums[i]>nums[first]){
                second=i;
                break;
            }
        }
        swap(nums[first],nums[second]);
        reverse(nums.begin()+first+1,nums.end());
        return ;
    }
};