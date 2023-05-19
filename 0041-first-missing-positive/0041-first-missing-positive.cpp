class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          sort(nums.begin(),nums.end());
          int n=nums.size();
          int last=0; 
        int i=0;
        while(i<n && nums[i]<=0) i++;
        if(i>=n)
              return last+1;
         while(i<n && nums[i]-last<=1){
             last=nums[i];
             i++;
         }
        return  last+1;
         
    }
};