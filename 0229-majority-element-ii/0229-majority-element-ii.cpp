class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          vector<int>ans;
          int c1=0;
          int c2=0;
          int a1=-1;
          int n=nums.size();
          int a2=-1;
          for(int i=0;i<n;++i){
              if(c1==0 && a2!=nums[i]){
                    a1=nums[i];
                  c1+=1;
              }
              else if(a1==nums[i]){
                  c1+=1;
              }
              else if(c2==0){
                  c2+=1;
                  a2=nums[i];
              }
              else if(a2==nums[i]){
                  c2+=1;
                  a2=nums[i];
              }
              else{
                  c1-=1;
                  c2-=1;
              }
          }
          c1=0;
          c2=0;
          for(auto itr: nums){
              if(itr==a1){
                  c1+=1;
              }
              else if(itr==a2){
                  c2+=1;
              }
         }
        if(c1>(n/3)){
            ans.push_back(a1);
        }
        if(c2>(n/3)){
            ans.push_back(a2);
        }
        return ans;
    }
};