class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first=-1;
        int second=-1; 
        int n=nums.size();
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                first=i;
                break;
            }
        }   
        if(first==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>=0;--i){
            if(nums[i]>nums[first]){
                second=i;
                break;
            }
        }
       if(second==-1){
           return ;
        }
        else{
            swap(nums[first],nums[second]);
            reverse(nums.begin()+first+1,nums.end());
        }
        return ;
    }
};