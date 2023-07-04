class Solution {
public:
    void moveZeroes(vector<int>& nums) {
          int n=nums.size();
          int last=-1;
          for(int i=0;i<n;++i){
              if(nums[i]==0){
                  if(last==-1){
                      last=i;
                  }
              }
              else{ 
                  if(last!=-1){
                swap(nums[i],nums[last]);  
                      last++;
                  }
              }
          }
        return ;
    }
};