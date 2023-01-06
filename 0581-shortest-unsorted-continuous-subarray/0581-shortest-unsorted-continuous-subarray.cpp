class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
      int n=nums.size(); 
        int i=0; 
        int ind1=-1;
        int ind2=-1;
        int prevlow=0;
        int prevhigh=n-1;
        while(i<n){
            if(nums[i]<nums[prevlow]){
                ind2=i;
            }
            else{
                prevlow=i;
            }
            i++;
        }
        i=n-1;
        while(i>=0){
            if(nums[i]>nums[prevhigh]){
                ind1=i;
            }
            else{
                prevhigh=i;
            }
            i--;
        }
        if(ind1>=0 && ind2>=0)
            return ind2-ind1+1;
        return 0;
         
    }
};