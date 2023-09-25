class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
          int n=nums.size();
          int ans=0;
          set<int>s;
          for(auto it: nums){
              s.insert(it);
          }
          for(auto it: s){
              int c=1;
              if(s.find(it-1)==s.end()){
                  int x=it+1;
                  while(s.find(x)!=s.end()){
                      x+=1;
                      c+=1;
                  }
                  ans=max(ans,c);
              }
          }
          return ans;
    }
};