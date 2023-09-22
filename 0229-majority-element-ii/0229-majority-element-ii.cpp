class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
          int n=nums.size();
          vector<int>ans;
          int first=INT_MAX;
          int second=INT_MAX;
          int freq1=0;
          int freq2=0;
          for(auto itr: nums){
               if(freq1==0 && second!=itr){
                   first=itr;
                   freq1+=1;
               }
              else if(first==itr){
                  freq1+=1;
                  continue;
              }
               else if(freq2==0 && first!=itr){
                   second=itr;
                    freq2+=1;
               }
              else if(second==itr){
                   freq2+=1;
              }
              else{
                  freq1--;
                  freq2--;
              }
          }
          freq1=0;
          freq2=0;
          for(auto itr: nums){
              if(itr==first){
                  freq1+=1;
              }
              else if(itr==second){
                  freq2+=1;
              }
          }
        if(freq1>(n/3)){
            ans.push_back(first);
        }
        if(freq2>(n/3)){
            ans.push_back(second);
        }
        return ans;
    }
};