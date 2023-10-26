class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          int n=nums.size();
          if(n<=1) return n;
          int ans=0;
          set<int>s;
           for(auto itr: nums){
               s.insert(itr);
           }
           int curr=1;
           for(auto itr: s){
               if(s.find(itr+1)!=s.end()){
                      curr+=1;
               }
               else{
                   ans=max(ans,curr);
                   curr=1;
               }
           }
         return ans;
    }
};